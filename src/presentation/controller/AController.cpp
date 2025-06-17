#include "AController.hpp"
#include "../../core/HttpResponse.hpp"
#include "../../core/responses/MethodNotAllowedHttpResponse.hpp"
#include "../../core/responses/NotImplementedHttpResponse.hpp"

AController::AController()
{
}

AController::AController(const AController& other)
{
    (void)other;
}

AController& AController::operator=(const AController& other)
{
    (void)other;
    return *this;
}

AController::~AController()
{
}

HttpResponse AController::handleGet(const HttpRequest& request)
{
    (void)request;
    return createMethodNotAllowedResponse();
}

HttpResponse AController::handlePost(const HttpRequest& request)
{
    (void)request;
    return createMethodNotAllowedResponse();
}

HttpResponse AController::handleDelete(const HttpRequest& request)
{
    (void)request;
    return createMethodNotAllowedResponse();
}

bool AController::supportsMethod(const std::string& method) const
{
    return (method == "GET" || method == "POST" || method == "DELETE");
}

HttpResponse AController::createMethodNotAllowedResponse() const
{
    return MethodNotAllowedHttpResponse("HTTP method not supported by this controller");
}

HttpResponse AController::createNotImplementedResponse() const
{
    return NotImplementedHttpResponse("Method not implemented yet");
}
