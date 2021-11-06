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
// EasyContact Header Files
#include "../Executable/SingleUser.hpp"
#include "hv/HttpService.h"
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
  static void register_router(HttpService &router) {
    router.preprocessor = pre;
    router.postprocessor = post;

    // Login
    router.POST("/login/:RCSID/:Password",
                [](HttpRequest *req, HttpResponse *resp) {
                  const std::string Password = req->GetParam("Password");
                  const std::string RCSID = req->GetParam("RCSID");
                  // Sanity Check
                  if (Password == "" || RCSID == "") {
                    return 400;
                  }
                  if (BMC::AuthenticateLogin(RCSID, Password) == true) {
                    g_ActiveUsers.insert(std::pair<std::string, SingleUser>(
                        RCSID, SingleUser(RCSID, Password)));
                    return 200;
                  }
                  return 505;
                });
#if 0
    // contacts
    router->POST("/contacts/:contactName",
                 [](HttpRequest *req, HttpResponse *resp) {
                   std::string contactName = req->GetParam("contactName");
                   if (contactName == "") {
                     return 400;
                   }
                   std::string email = req->GetString("email");
                   if (newContact(new BCS::Key(contactName, email))) {
                     return 200;
                   }
                   return 406;
                 });

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

    router->GET("/contacts/all", [](HttpRequest *req, HttpResponse *resp) {
      std::unordered_set<BCS::Key> &contacts = getAllContacts();
      if (contacts.empty()) {
        return 404;
      }
      for (BCS::Key &k : contacts) {
        resp->json.push_back({{"name", k.Name}, {"email", k.Email}})
      }
      return 200;
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
