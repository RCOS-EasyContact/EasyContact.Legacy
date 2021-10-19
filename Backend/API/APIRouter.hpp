/**
 * RCOS-EasyContact
 * EasyContact/Backend/API
 * APIRouter.hpp
 * Copyright [2021] <RCOS-EasyContact>
 */
#ifndef BACKEND_API_APIROUTER_HPP_
#define BACKEND_API_APIROUTER_HPP_
#include "../ContactSystem/Books.hpp"
#include "hv/HttpService.h"

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

    // login
    router->POST("/login/:userName/:password",
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

    // templates [delete after finish]
    router->GET("", [](HttpRequest *req, HttpResponse *resp) { return 404; });

    router->POST("", [](HttpRequest *req, HttpResponse *resp) { return 404; });

    router->PUT("", [](HttpRequest *req, HttpResponse *resp) { return 404; });

    router->Delete("",
                   [](HttpRequest *req, HttpResponse *resp) { return 404; });

    router->PATCH("", [](HttpRequest *req, HttpResponse *resp) { return 404; });
  }
};
#endif  // BACKEND_API_APIROUTER_HPP_
