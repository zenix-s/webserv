#include "HttpRequestHandler.hpp"
#include "core/HttpRequest.hpp"
#include "core/HttpResponse.hpp"

HttpRequestHandler::HttpRequestHandler() : _controllerRegistry()
{
}

HttpRequestHandler::HttpRequestHandler(const HttpRequestHandler& other) : _controllerRegistry(other._controllerRegistry)
{
}

HttpRequestHandler& HttpRequestHandler::operator=(const HttpRequestHandler& other)
{
    if (this != &other)
    {
        _controllerRegistry = other._controllerRegistry;
    }
    return *this;
}

HttpRequestHandler::~HttpRequestHandler()
{
}

HttpResponse HttpRequestHandler::handle(const HttpRequest& request)
{
    if (!request.isValid())
    {
        HttpResponse response;
        handleBadRequest(response);
        return response;
    }

    // Delegar el procesamiento al controlador correspondiente
    return _controllerRegistry.processRequest(request);
}

// Maneja solicitudes inválidas o no soportadas
void HttpRequestHandler::handleBadRequest(HttpResponse& response)
{
    response.setStatus(400, "Bad Request");
    response.setHeader("Content-Type", "text/plain");
    response.setBody("Bad Request");
}
