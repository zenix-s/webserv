#include "BadRequestHttpResponse.hpp"

// Default constructor - creates a basic 400 Bad Request response
BadRequestHttpResponse::BadRequestHttpResponse() : HttpResponse()
{
    setStatus(400, "Bad Request");
    setHeader("Content-Type", "text/plain");
    setBody("Bad Request");
}

// Constructor with body
BadRequestHttpResponse::BadRequestHttpResponse(const std::string& body) : HttpResponse()
{
    setStatus(400, "Bad Request");
    setHeader("Content-Type", "text/plain");
    setBody(body);
}

// Constructor with body and content type
BadRequestHttpResponse::BadRequestHttpResponse(const std::string& body, const std::string& contentType) : HttpResponse()
{
    setStatus(400, "Bad Request");
    setHeader("Content-Type", contentType);
    setBody(body);
}

// Copy constructor
BadRequestHttpResponse::BadRequestHttpResponse(const BadRequestHttpResponse& other) : HttpResponse(other)
{
}

// Assignment operator
BadRequestHttpResponse& BadRequestHttpResponse::operator=(const BadRequestHttpResponse& other)
{
    if (this != &other)
    {
        HttpResponse::operator=(other);
    }
    return *this;
}

// Destructor
BadRequestHttpResponse::~BadRequestHttpResponse()
{
}