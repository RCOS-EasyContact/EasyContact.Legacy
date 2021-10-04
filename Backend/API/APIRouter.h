/**
 * RCOS-EasyContact
 * EasyContact/Backend/API
 * APIRouter.h
 * Copyright [2021] <RCOS-EasyContact>
 */
#ifndef BACKEND_API_APIROUTER_H_
#define BACKEND_API_APIROUTER_H_

// #include "ConatctSystem/Resources.h"
#include "hv/HttpService.h"

class APIRouter{
 public:
    static int pre(HttpRequest* req, HttpResponse* resp) {
        resp->content_type = APPLICATION_JSON;
        req->ParseBody();
        return 0;
    }

    static int post(HttpRequest* req, HttpResponse* resp) {
        // BYPASSUNUSED(req);
        return 0;
    }

    static void register_router(HttpService* router) {
        router->preprocessor = pre;
        router->postprocessor = post;

        router->GET("", [](HttpRequest* req, HttpResponse* resp) {
            return 404;
        });

        router->POST("", [](HttpRequest* req, HttpResponse* resp) {
            return 404;
        });

        router->PUT("", [](HttpRequest* req, HttpResponse* resp) {
            return 404;
        });

        router->Delete("", [](HttpRequest* req, HttpResponse* resp) {
            return 404;
        });

        router->PATCH("", [](HttpRequest* req, HttpResponse* resp) {
            return 404;
        });
    }
};

#endif  // BACKEND_API_APIROUTER_H_
