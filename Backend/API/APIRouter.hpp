/**
 * RCOS-EasyContact
 * EasyContact/Backend/API
 * APIRouter.hpp
 * Copyright [2021] <RCOS-EasyContact>
 */
#ifndef BACKEND_API_APIROUTER_HPP_
#define BACKEND_API_APIROUTER_HPP_
// Resolve Conflict with Libboost
#undef defer
// C++ Standard Library
#include <string>
// Standard Template Library
#include <unordered_map>
#include <utility>
#include <vector>
// Libhv Library
#include "hv/HttpService.h"
// EasyContact Header Files
#include "../Executable/SingleUser.hpp"
#include "../Executable/SysLogs.hpp"
#include "UserToken.hpp"
// Global Representation
extern std::unordered_map<std::string, SingleUser> g_ActiveUsers;
class APIRouter {
 public:
  static int pre(HttpRequest *req, HttpResponse *resp) {
    resp->content_type = APPLICATION_JSON;
    req->ParseBody();
    return 0;
  }
  static int post(HttpRequest *req, HttpResponse *resp) { return 0; }
  static void register_router(HttpService *router) {
    router->preprocessor = pre;
    router->postprocessor = post;
    // Attempt Sign In To RPI's Email Server
    router->POST("/Login", [](HttpRequest *req, HttpResponse *resp) {
      SYSLOG::PrintRequest("POST\t", "/Login");
      try {
        const std::string &RCSID = req->json["RCSID"];
        const std::string &Password = req->json["Password"];
        if (BMC::AuthenticateLogin(RCSID, Password) == true) {
          const std::string Token = AUT::GenerateToken();
          g_ActiveUsers.insert(std::pair<std::string, SingleUser>(
              Token, SingleUser(RCSID, Password)));
          resp->json["Token"] = Token;
          return 200;  // OK
        } else {
          return 511;  // Network Authentication Required
        }
      } catch (const std::exception &Err) {
        SYSLOG::PrintException(Err);
      }
      return 500;  // Internal Server Error
    });
    // Retrieve All Contact Names
    router->GET("/Contacts/Retrieve/AllNames", [](HttpRequest *req,
                                                  HttpResponse *resp) {
      SYSLOG::PrintRequest("GET\t", "/Contacts/Retrieve/AllNames");
      try {
        const std::string &Token = req->json["Token"];
        const std::unordered_map<std::string, SingleUser>::const_iterator User =
            g_ActiveUsers.find(Token);
        // Verify User Is Current Active
        if (User == g_ActiveUsers.end()) {
          return 401;  // Unauthorized
        }
        const std::vector<std::string> &AllNames =
            User->second.SQLContacts.getAllNames();
        for (const std::string &i : AllNames) {
          resp->json.push_back(i);
        }
        return 200;  // OK
      } catch (const std::exception &Err) {
        SYSLOG::PrintException(Err);
      }
      return 500;  // Internal Server Error
    });
    // Retrieve All Tags
    router->GET("/Contacts/Retrieve/AllTags", [](HttpRequest *req,
                                                 HttpResponse *resp) {
      SYSLOG::PrintRequest("GET\t", "/Contacts/Retrieve/AllTags");
      try {
        const std::string &Token = req->json["Token"];
        const std::unordered_map<std::string, SingleUser>::const_iterator User =
            g_ActiveUsers.find(Token);
        // Verify User Is Current Active
        if (User == g_ActiveUsers.end()) {
          return 401;  // Unauthorized
        }
        const std::vector<std::string> &TagContains =
            User->second.SQLContacts.getAllTags();
        for (const std::string &i : TagContains) {
          resp->json.push_back(i);
        }
        return 200;  // OK
      } catch (const std::exception &Err) {
        SYSLOG::PrintException(Err);
      }
      return 500;  // Internal Server Error
    });
    // Retrieve All Contacts Within One Tag
    router->GET("/Contacts/Retrieve/TagContains", [](HttpRequest *req,
                                                     HttpResponse *resp) {
      try {
        const std::string &Token = req->json["Token"];
        const std::string &Name = req->json["Name"];
        const std::unordered_map<std::string, SingleUser>::const_iterator User =
            g_ActiveUsers.find(Token);
        // Verify User Is Current Active
        if (User == g_ActiveUsers.end()) {
          return 401;  // Unauthorized
        }
        const std::vector<std::string> &AllTags =
            User->second.SQLContacts.getTagContains(Name);
        for (const std::string &i : AllTags) {
          resp->json.push_back(i);
        }
        return 200;  // OK
      } catch (const std::exception &Err) {
        SYSLOG::PrintException(Err);
      }
      return 500;  // Internal Server Error
    });
    // Retrieve Email Address For One Contact
    router->GET("/Contacts/Retrieve/Email", [](HttpRequest *req,
                                               HttpResponse *resp) {
      try {
        const std::string &Token = req->json["Token"];
        const std::string &Name = req->json["Name"];
        const std::unordered_map<std::string, SingleUser>::const_iterator User =
            g_ActiveUsers.find(Token);
        // Verify User Is Current Active
        if (User == g_ActiveUsers.end()) {
          return 401;  // Unauthorized
        }
        const std::string &EmailAddress =
            User->second.SQLContacts.getEmailAddress(Name);
        resp->json.push_back(EmailAddress);
        return 200;  // OK
      } catch (const std::exception &Err) {
        SYSLOG::PrintException(Err);
      }
      return 500;  // Internal Server Error
    });
    // Create New Contact
    router->POST(
        "/Contacts/Create/Contact", [](HttpRequest *req, HttpResponse *resp) {
          try {
            const std::string &Token = req->json["Token"];
            const std::string &Name = req->json["Name"];
            const std::string &Email = req->json["Email"];
            const std::unordered_map<std::string, SingleUser>::iterator User =
                g_ActiveUsers.find(Token);
            // Verify User Is Current Active
            if (User == g_ActiveUsers.end()) {
              return 401;  // Unauthorized
            }
            if (User->second.SQLContacts.newContact(Name, Email) == true) {
              return 200;  // OK
            } else {
              return 409;  // Conflict
            }
          } catch (const std::exception &Err) {
            SYSLOG::PrintException(Err);
          }
          return 500;  // Internal Server Error
        });
    // Create New Tag
    router->POST(
        "/Contacts/Create/Tag", [](HttpRequest *req, HttpResponse *resp) {
          try {
            const std::string &Token = req->json["Token"];
            const std::string &TagName = req->json["TagName"];
            const std::unordered_map<std::string, SingleUser>::iterator User =
                g_ActiveUsers.find(Token);
            // Verify User Is Current Active
            if (User == g_ActiveUsers.end()) {
              return 401;  // Unauthorized
            }
            if (User->second.SQLContacts.newTag(TagName) == true) {
              return 200;  // OK
            } else {
              return 409;  // Conflict
            }
          } catch (const std::exception &Err) {
            SYSLOG::PrintException(Err);
          }
          return 500;  // Internal Server Error
        });
    // Assign Tag to One Existing Contact
    router->PUT(
        "/Contacts/Assign/Contact", [](HttpRequest *req, HttpResponse *resp) {
          try {
            const std::string &Token = req->json["Token"];
            const std::string &TagName = req->json["TagName"];
            const std::string &Name = req->json["Name"];
            const std::unordered_map<std::string, SingleUser>::iterator User =
                g_ActiveUsers.find(Token);
            // Verify User Is Current Active
            if (User == g_ActiveUsers.end()) {
              return 401;  // Unauthorized
            }
            if (User->second.SQLContacts.assignTagTo(TagName, Name) == true) {
              return 200;  // OK
            } else {
              return 409;  // Conflict
            }
          } catch (const std::exception &Err) {
            SYSLOG::PrintException(Err);
          }
          return 500;  // Internal Server Error
        });
    // Remove Tag For One Existing Contact
    router->Delete(
        "/Contacts/Unassign/Contact", [](HttpRequest *req, HttpResponse *resp) {
          try {
            const std::string &Token = req->json["Token"];
            const std::string &TagName = req->json["TagName"];
            const std::string &Name = req->json["Name"];
            const std::unordered_map<std::string, SingleUser>::iterator User =
                g_ActiveUsers.find(Token);
            // Verify User Is Current Active
            if (User == g_ActiveUsers.end()) {
              return 401;  // Unauthorized
            }
            if (User->second.SQLContacts.removeTagFor(TagName, Name) == true) {
              return 200;  // OK
            } else {
              return 409;  // Conflict
            }
          } catch (const std::exception &Err) {
            SYSLOG::PrintException(Err);
          }
          return 500;  // Internal Server Error
        });
    // Remove Existing Contact
    router->Delete(
        "/Contacts/Remove/Contact", [](HttpRequest *req, HttpResponse *resp) {
          try {
            const std::string &Token = req->json["Token"];
            const std::string &Name = req->json["Name"];
            const std::unordered_map<std::string, SingleUser>::iterator User =
                g_ActiveUsers.find(Token);
            // Verify User Is Current Active
            if (User == g_ActiveUsers.end()) {
              return 401;  // Unauthorized
            }
            if (User->second.SQLContacts.removeContact(Name) == true) {
              return 200;  // OK
            } else {
              return 409;  // Conflict
            }
          } catch (const std::exception &Err) {
            SYSLOG::PrintException(Err);
          }
          return 500;  // Internal Server Error
        });
    // Remove Existing Tag
    router->Delete(
        "/Contacts/Remove/Tag", [](HttpRequest *req, HttpResponse *resp) {
          try {
            const std::string &Token = req->json["Token"];
            const std::string &TagName = req->json["TagName"];
            const std::unordered_map<std::string, SingleUser>::iterator User =
                g_ActiveUsers.find(Token);
            // Verify User Is Current Active
            if (User == g_ActiveUsers.end()) {
              return 401;  // Unauthorized
            }
            if (User->second.SQLContacts.removeTag(TagName) == true) {
              return 200;  // OK
            } else {
              return 409;  // Conflict
            }
          } catch (const std::exception &Err) {
            SYSLOG::PrintException(Err);
          }
          return 500;  // Internal Server Error
        });
  }
};
#endif  // BACKEND_API_APIROUTER_HPP_
