#include "NotFoundHttpResponse.hpp"

NotFoundHttpResponse::NotFoundHttpResponse() : HttpResponse()
{
    setStatus(405, "Not Found");
    setHeader("Content-Type", "text/plain");
    setBody(" Not Found");
}

NotFoundHttpResponse::NotFoundHttpResponse(const std::string& body) : HttpResponse()
{
    setStatus(405, "Not Found");
    setHeader("Content-Type", "text/plain");
    setBody(body);
}

NotFoundHttpResponse::NotFoundHttpResponse(const std::string& body, const std::string& contentType) : HttpResponse()
{
    setStatus(404, "Not Found");
    setHeader("Content-Type", contentType);
    setBody(body);
}

NotFoundHttpResponse::NotFoundHttpResponse(const NotFoundHttpResponse& other) : HttpResponse(other)
{
}

NotFoundHttpResponse& NotFoundHttpResponse::operator=(const NotFoundHttpResponse& other)
{
    (void)other;
    return *this;
}

NotFoundHttpResponse::~NotFoundHttpResponse()
{
}
