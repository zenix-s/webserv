#include "NotImplementedHttpResponse.hpp"

NotImplementedHttpResponse::NotImplementedHttpResponse() : HttpResponse()
{
    setStatus(501, "Not Implemented");
    setHeader("Content-Type", "text/plain");
    setBody("Not Implemented");
}

NotImplementedHttpResponse::NotImplementedHttpResponse(const std::string& body) : HttpResponse()
{
    setStatus(501, "Not Implemented");
    setHeader("Content-Type", "text/plain");
    setBody(body);
}

NotImplementedHttpResponse::NotImplementedHttpResponse(const std::string& body, const std::string& contentType)
    : HttpResponse()
{
    setStatus(501, "Not Implemented");
    setHeader("Content-Type", contentType);
    setBody(body);
}

NotImplementedHttpResponse::NotImplementedHttpResponse(const NotImplementedHttpResponse& other) : HttpResponse(other)
{
}

NotImplementedHttpResponse& NotImplementedHttpResponse::operator=(const NotImplementedHttpResponse& other)
{
    if (this != &other)
    {
        HttpResponse::operator=(other);
    }
    return *this;
}

NotImplementedHttpResponse::~NotImplementedHttpResponse()
{
}
