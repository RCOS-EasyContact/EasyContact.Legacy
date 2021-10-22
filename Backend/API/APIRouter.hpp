/**
 * RCOS-EasyContact
 * EasyContact/Backend/API
 * APIRouter.hpp
 * Copyright [2021] <RCOS-EasyContact>
 */
#ifndef BACKEND_API_APIROUTER_HPP_
#define BACKEND_API_APIROUTER_HPP_
// C++ Standard Library
#include <string>
// Standard Template Library
#include <unordered_set>
// Local Headers
#include "../ContactSystem/Books.hpp"
#include "hv/HttpService.h"

class APIRouter {
 public:
  static int pre(HttpRequest *req, HttpResponse *resp) {
    resp->content_type = APPLICATION_JSON;
    req->ParseBody();
    return 0;
  }

  static int post(HttpRequest *req, HttpResponse *resp) { return 0;}

  static void register_router(HttpService *router) {
    router->preprocessor = pre;
    router->postprocessor = post;

    // login
    router->
    POST("/login/:userName/:password",
       [](HttpRequest *req, HttpResponse *resp) {
          std::string userName = req->GetParam("userName");
          std::string password = req->GetParam("password");
          if (userName == "" || password == "") {
            return 400;
          }
          if (true) {
            return 200;
          }
          return 505;
       });

    // contacts
    router->POST("/contacts/:contactName",
      [](HttpRequest *req, HttpResponse *resp) {
        std::string contactName = req->GetParam("contactName");
        if (contactName == "") {
          return 400;
        }
        std::string email = req->GetString("email");
        if (newContact(new Key(contactName, email))) {
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
      std::unordered_set<BCS::Key>& contacts = getAllContacts();
      if (contacts.empty()) {
        return 404;
      }
      for (BCS::Key& k : contacts) {
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
        for (std::string& tag : getNameInTags(contactName)) {
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
      std::unordered_set<std::string> contacts = getTagContains(tagName);
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

    router->Delete("",
      [](HttpRequest *req, HttpResponse *resp) {
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
    router->GET("", [](HttpRequest *req, HttpResponse *resp) { return 404;});

    router->POST("", [](HttpRequest *req, HttpResponse *resp) { return 404;});

    router->PUT("", [](HttpRequest *req, HttpResponse *resp) { return 404;});

    router->Delete("",
      [](HttpRequest *req, HttpResponse *resp) { return 404;});

    router->PATCH("", [](HttpRequest *req, HttpResponse *resp) { return 404;});
  }
};
#endif  // BACKEND_API_APIROUTER_HPP_
