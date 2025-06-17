#include "OkHttpResponse.hpp"

// Default constructor - creates a basic 200 OK response
OkHttpResponse::OkHttpResponse() : HttpResponse()
{
    setStatus(200, "OK");
    setHeader("Content-Type", "text/plain");
    setBody("OK");
}

// Constructor with body
OkHttpResponse::OkHttpResponse(const std::string& body) : HttpResponse()
{
    setStatus(200, "OK");
    setHeader("Content-Type", "text/plain");
    setBody(body);
}

// Constructor with body and content type
OkHttpResponse::OkHttpResponse(const std::string& body, const std::string& contentType) : HttpResponse()
{
    setStatus(200, "OK");
    setHeader("Content-Type", contentType);
    setBody(body);
}

// Copy constructor
OkHttpResponse::OkHttpResponse(const OkHttpResponse& other) : HttpResponse(other)
{
}

// Assignment operator
OkHttpResponse& OkHttpResponse::operator=(const OkHttpResponse& other)
{
    if (this != &other)
    {
        HttpResponse::operator=(other);
    }
    return *this;
}

// Destructor
OkHttpResponse::~OkHttpResponse()
{
}