#include "MethodNotAllowedHttpResponse.hpp"

// Default constructor - creates a basic 405 Method Not Allowed response
MethodNotAllowedHttpResponse::MethodNotAllowedHttpResponse() : HttpResponse()
{
    setStatus(405, "Method Not Allowed");
    setHeader("Content-Type", "text/plain");
    setBody("Method Not Allowed");
}

// Constructor with body
MethodNotAllowedHttpResponse::MethodNotAllowedHttpResponse(const std::string& body) : HttpResponse()
{
    setStatus(405, "Method Not Allowed");
    setHeader("Content-Type", "text/plain");
    setBody(body);
}

// Constructor with body and content type
MethodNotAllowedHttpResponse::MethodNotAllowedHttpResponse(const std::string& body, const std::string& contentType) : HttpResponse()
{
    setStatus(405, "Method Not Allowed");
    setHeader("Content-Type", contentType);
    setBody(body);
}

// Copy constructor
MethodNotAllowedHttpResponse::MethodNotAllowedHttpResponse(const MethodNotAllowedHttpResponse& other) : HttpResponse(other)
{
}

// Assignment operator
MethodNotAllowedHttpResponse& MethodNotAllowedHttpResponse::operator=(const MethodNotAllowedHttpResponse& other)
{
    if (this != &other)
    {
        HttpResponse::operator=(other);
    }
    return *this;
}

// Destructor
MethodNotAllowedHttpResponse::~MethodNotAllowedHttpResponse()
{
}