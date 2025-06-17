#include "MethodNotAllowedHttpResponse.hpp"

MethodNotAllowedHttpResponse::MethodNotAllowedHttpResponse() : HttpResponse()
{
    setStatus(405, "Method Not Allowed");
    setHeader("Content-Type", "text/plain");
    setBody("Method Not Allowed");
}

MethodNotAllowedHttpResponse::MethodNotAllowedHttpResponse(const std::string& body) : HttpResponse()
{
    setStatus(405, "Method Not Allowed");
    setHeader("Content-Type", "text/plain");
    setBody(body);
}

MethodNotAllowedHttpResponse::MethodNotAllowedHttpResponse(const std::string& body, const std::string& contentType)
    : HttpResponse()
{
    setStatus(405, "Method Not Allowed");
    setHeader("Content-Type", contentType);
    setBody(body);
}

MethodNotAllowedHttpResponse::MethodNotAllowedHttpResponse(const MethodNotAllowedHttpResponse& other)
    : HttpResponse(other)
{
}

MethodNotAllowedHttpResponse& MethodNotAllowedHttpResponse::operator=(const MethodNotAllowedHttpResponse& other)
{
    (void)other;
    return *this;
}

MethodNotAllowedHttpResponse::~MethodNotAllowedHttpResponse()
{
}
