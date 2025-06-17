#include "NotImplementedHttpResponse.hpp"

// Default constructor - creates a basic 501 Not Implemented response
NotImplementedHttpResponse::NotImplementedHttpResponse() : HttpResponse()
{
    setStatus(501, "Not Implemented");
    setHeader("Content-Type", "text/plain");
    setBody("Not Implemented");
}

// Constructor with body
NotImplementedHttpResponse::NotImplementedHttpResponse(const std::string& body) : HttpResponse()
{
    setStatus(501, "Not Implemented");
    setHeader("Content-Type", "text/plain");
    setBody(body);
}

// Constructor with body and content type
NotImplementedHttpResponse::NotImplementedHttpResponse(const std::string& body, const std::string& contentType) : HttpResponse()
{
    setStatus(501, "Not Implemented");
    setHeader("Content-Type", contentType);
    setBody(body);
}

// Copy constructor
NotImplementedHttpResponse::NotImplementedHttpResponse(const NotImplementedHttpResponse& other) : HttpResponse(other)
{
}

// Assignment operator
NotImplementedHttpResponse& NotImplementedHttpResponse::operator=(const NotImplementedHttpResponse& other)
{
    if (this != &other)
    {
        HttpResponse::operator=(other);
    }
    return *this;
}

// Destructor
NotImplementedHttpResponse::~NotImplementedHttpResponse()
{
}