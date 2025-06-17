#include "AController.hpp"
#include "../../core/HttpResponse.hpp"
#include "../../core/responses/MethodNotAllowedHttpResponse.hpp"
#include "../../core/responses/NotImplementedHttpResponse.hpp"

// Protected constructor
AController::AController()
{
}

// Protected copy constructor
AController::AController(const AController& other)
{
    (void)other; // No state to copy in base class
}

// Protected assignment operator
AController& AController::operator=(const AController& other)
{
    (void)other; // No state to copy in base class
    return *this;
}

// Virtual destructor
AController::~AController()
{
}

// Default GET implementation - returns Method Not Allowed
HttpResponse AController::handleGet(const HttpRequest& request)
{
    (void)request; // Unused parameter
    return createMethodNotAllowedResponse();
}

// Default POST implementation - returns Method Not Allowed
HttpResponse AController::handlePost(const HttpRequest& request)
{
    (void)request; // Unused parameter
    return createMethodNotAllowedResponse();
}

// Default DELETE implementation - returns Method Not Allowed
HttpResponse AController::handleDelete(const HttpRequest& request)
{
    (void)request; // Unused parameter
    return createMethodNotAllowedResponse();
}

// Default method support check
bool AController::supportsMethod(const std::string& method) const
{
    return (method == "GET" || method == "POST" || method == "DELETE");
}

// Helper method to create 405 Method Not Allowed response
HttpResponse AController::createMethodNotAllowedResponse() const
{
    return MethodNotAllowedHttpResponse("HTTP method not supported by this controller");
}

// Helper method to create 501 Not Implemented response
HttpResponse AController::createNotImplementedResponse() const
{
    return NotImplementedHttpResponse("Method not implemented yet");
}