#ifndef EASYCONTACT_APIROUTER_H_
#define EASYCONTACT_APIROUTER_H_

#include "ConatctSystem/Resources.h"
#include "hv/HttpService.h"

class APIRouter{
    public:

    static int pre(HttpRequest* req, HttpResponse* resp) {
        resp->content_type = APPLICATION_JSON;
        req->ParseBody();
        return 0;
    };

    static int post(HttpRequest* req, HttpResponse* resp) {
        BYPASSUNUSED(req);
        return 0;
    };

    static void register_router(HttpService& router) {
        router.preprocessor = pre;
        router.postprocessor = post;
        
        router.GET();

        router.POST();

        router.PUT();

        router.DELETE();

        router.PATCH();
    };

}


#endif