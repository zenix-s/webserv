#include "BadRequestHttpResponse.hpp"

BadRequestHttpResponse::BadRequestHttpResponse() : HttpResponse()
{
    setStatus(400, "Bad Request");
    setHeader("Content-Type", "text/plain");
    setBody("Bad Request");
}

BadRequestHttpResponse::BadRequestHttpResponse(const std::string& body) : HttpResponse()
{
    setStatus(400, "Bad Request");
    setHeader("Content-Type", "text/plain");
    setBody(body);
}

BadRequestHttpResponse::BadRequestHttpResponse(const std::string& body, const std::string& contentType) : HttpResponse()
{
    setStatus(400, "Bad Request");
    setHeader("Content-Type", contentType);
    setBody(body);
}

BadRequestHttpResponse::BadRequestHttpResponse(const BadRequestHttpResponse& other) : HttpResponse(other)
{
}

BadRequestHttpResponse& BadRequestHttpResponse::operator=(const BadRequestHttpResponse& other)
{
    (void)other;
    return *this;
}

BadRequestHttpResponse::~BadRequestHttpResponse()
{
}
