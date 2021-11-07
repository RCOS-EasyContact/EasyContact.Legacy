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
            if (User->second.SQLContacts.newTag(TagNmae) == true) {
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
        if (User->second.SQLContacts.assignTagTo(TagNmae, Name) == true) {
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
            if (User->second.SQLContacts.removeTagFor(TagNmae, Name) == true) {
              return 200;  // OK
            } else {
              return 409;  // Conflict
            }
          } catch (const std::exception &Err) {
            SYSLOG::PrintException(Err);
          }
          return 500;  // Internal Server Error
        });
#if 0
    router->Delete("/contacts/:contactName",
                   [](HttpRequest *req, HttpResponse *resp) {
                     std::string contactName = req->GetParam("contactName");
                     if (contactName == "") {
                       return 400;
                     }
                     if (removeContact(contactName)) {
                       return 200;
                     }
                     return 404;
                   });

    

    router->GET("/contacts/tag/:contactName",
                [](HttpRequest *req, HttpResponse *resp) {
                  std::string contactName = req->GetParam("contactName");
                  if (contactName == "") {
                    return 400;
                  }
                  for (std::string &tag : getNameInTags(contactName)) {
                    resp->json.push_back({"tag", tag});
                  }
                  return 200;
                });

    router->Delete("/contacts/tag/:contactName",
                   [](HttpRequest *req, HttpResponse *resp) {
                     std::string contactName = req->GetParam("contactName");
                     if (contactName == "") {
                       return 400;
                     }
                     clearTagFor(contactName);
                     return 200;
                   });

    // tags
    router->GET("/tags/:tagName", [](HttpRequest *req, HttpResponse *resp) {
      std::string tagName = req->GetParam("tagName");
      if (tagName == "") {
        return 400;
      }
      std::vector<std::string> contacts = getTagContains(tagName);
      if (contacts.empty()) {
        return 404;
      }
      for (std::string &name : contacts) {
        resp->json.push_back({"name", name});
        return 200;
      }
      return 400;
    });

    router->GET("/tags/exist/:tagName",
                [](HttpRequest *req, HttpResponse *resp) {
                  std::string tagName = req->GetParam("tagName");
                  if (getAllTags().find(tagName)) {
                    return 200;
                  }
                  return 404;
                });

    router->POST("/tags/:tagName", [](HttpRequest *req, HttpResponse *resp) {
      std::string tagName = req->GetParam("tagName");
      if (tagName == "") {
        return 400;
      }
      if (newTag(tagName)) {
        return 200;
      }
      return 406;
    });

    router->Delete("/tags/:tagName", [](HttpRequest *req, HttpResponse *resp) {
      std::string tagName = req->GetParam("tagName");
      if (tagName == "") {
        return 400;
      }
      if (removeTag(tagName)) {
        return 200;
      }
      return 404;
    });

    // books
    router->PUT("/books/:contactName/:tagName",
                [](HttpRequest *req, HttpResponse *resp) {
                  std::string contactName = req->GetParam("contactName");
                  std::string tagName = req->GetParam("tagName");
                  if (contactName == "" || tagName == "") {
                    return 400;
                  }
                  if (!getAllTags.find(tagName)) {
                    return 404;
                  }
                  assignTagTo(tagName, contactName);
                  return 200;
                });

    router->Delete("", [](HttpRequest *req, HttpResponse *resp) {
      std::string contactName = req->GetParam("contactName");
      std::string tagName = req->GetParam("tagName");
      if (contactName == "" || tagName == "") {
        return 400;
      }
      if (!getNameInTags(contactName).find(tagName)) {
        return 404;
      }
      removeTagFor(tagName, contactName);
      return 200;
    });

    // templates [delete after finish]
    router->GET("", [](HttpRequest *req, HttpResponse *resp) { return 404; });

    router->POST("", [](HttpRequest *req, HttpResponse *resp) { return 404; });

    router->PUT("", [](HttpRequest *req, HttpResponse *resp) { return 404; });

    router->Delete("",
                   [](HttpRequest *req, HttpResponse *resp) { return 404; });

    router->PATCH("", [](HttpRequest *req, HttpResponse *resp) { return 404; });
#endif
  }
};
#endif  // BACKEND_API_APIROUTER_HPP_
