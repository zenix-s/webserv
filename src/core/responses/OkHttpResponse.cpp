#include "OkHttpResponse.hpp"

OkHttpResponse::OkHttpResponse() : HttpResponse()
{
    setStatus(200, "OK");
    setHeader("Content-Type", "text/plain");
    setBody("OK");
}

OkHttpResponse::OkHttpResponse(const std::string& body) : HttpResponse()
{
    setStatus(200, "OK");
    setHeader("Content-Type", "text/plain");
    setBody(body);
}

OkHttpResponse::OkHttpResponse(const std::string& body, const std::string& contentType) : HttpResponse()
{
    setStatus(200, "OK");
    setHeader("Content-Type", contentType);
    setBody(body);
}

OkHttpResponse::OkHttpResponse(const OkHttpResponse& other) : HttpResponse(other)
{
}

OkHttpResponse& OkHttpResponse::operator=(const OkHttpResponse& other)
{
    if (this != &other)
    {
        HttpResponse::operator=(other);
    }
    return *this;
}

OkHttpResponse::~OkHttpResponse()
{
}
