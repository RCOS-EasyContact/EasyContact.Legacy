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
    if (req->method == HTTP_OPTIONS) {
        resp->headers["Access-Control-Allow-Origin"] = req->GetHeader("Origin", "*");
        resp->headers["Access-Control-Allow-Methods"] = req->GetHeader("Access-Control-Request-Method", "OPTIONS, HEAD, GET, POST, PUT, DELETE, PATCH");
        resp->headers["Access-Control-Allow-Headers"] = req->GetHeader("Access-Control-Request-Headers", "Content-Type");
        return HTTP_STATUS_NO_CONTENT;
    }
    resp->content_type = APPLICATION_JSON;
    std::cout << req->Dump(true, true).c_str() << std::endl;
    std::cout << req->Dump(false, false).c_str() << std::endl;
    req->ParseBody();
    return 0;
  }
  static int post(HttpRequest *req, HttpResponse *resp) { return 0; }
  static void register_router(HttpService *router) {
    router->preprocessor = pre;
    router->postprocessor = post;
    // Attempt Sign In To RPI's Email Server
    router->POST("/Login", [](HttpRequest *req, HttpResponse *resp) {
      SYSLOG::PrintRequest("POST->", "/Login");
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
    router->GET("/Contacts/AllNames", [](HttpRequest *req, HttpResponse *resp) {
      SYSLOG::PrintRequest("GET->", "/Contacts/AllNames");
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
    router->GET("/Contacts/AllTags", [](HttpRequest *req, HttpResponse *resp) {
      SYSLOG::PrintRequest("GET->", "/Contacts/AllTags");
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
    router->GET("/Contacts/TagContains", [](HttpRequest *req,
                                            HttpResponse *resp) {
      SYSLOG::PrintRequest("GET->", "/Contacts/TagContains");
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
    router->GET("/Contacts/Email", [](HttpRequest *req, HttpResponse *resp) {
      SYSLOG::PrintRequest("GET->", "/Contacts/Email");
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
    router->POST("/Contacts/New", [](HttpRequest *req, HttpResponse *resp) {
      SYSLOG::PrintRequest("POST->", "/Contacts/New");
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
    router->POST("/Contacts/Tag", [](HttpRequest *req, HttpResponse *resp) {
      SYSLOG::PrintRequest("POST->", "/Contacts/Tag");
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
    router->PUT("/Contacts/Assign", [](HttpRequest *req, HttpResponse *resp) {
      SYSLOG::PrintRequest("PUT->", "/Contacts/Assign");
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
        "/Contacts/Unassign", [](HttpRequest *req, HttpResponse *resp) {
          SYSLOG::PrintRequest("Delete->", "/Contacts/Unassign");
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
        "/Contacts/Remove", [](HttpRequest *req, HttpResponse *resp) {
          SYSLOG::PrintRequest("Delete->", "/Contacts/Remove");
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
        "/Contacts/RemoveTag", [](HttpRequest *req, HttpResponse *resp) {
          SYSLOG::PrintRequest("Delete->", "/Contacts/RemoveTag");
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
