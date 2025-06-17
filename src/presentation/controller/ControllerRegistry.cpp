#include "ControllerRegistry.hpp"
#include "../../core/responses/MethodNotAllowedHttpResponse.hpp"
#include "IController.hpp"
#include "TaskController.hpp"
#include "UserController.hpp"

ControllerRegistry::ControllerRegistry()
{
}

ControllerRegistry::ControllerRegistry(const ControllerRegistry& other)
{
    (void)other;
}

ControllerRegistry& ControllerRegistry::operator=(const ControllerRegistry& other)
{
    (void)other;
    return *this;
}

ControllerRegistry::~ControllerRegistry()
{
}

HttpResponse ControllerRegistry::processRequest(const HttpRequest& request)
{
    const std::string& url = request.getUrl();

    if (matchesRoute(url, "/task"))
    {
        return handleTaskRoute(request);
    }
    else if (matchesRoute(url, "/user"))
    {
        return handleUserRoute(request);
    }

    return handleNotFound();
}

HttpResponse ControllerRegistry::handleTaskRoute(const HttpRequest& request)
{
    TaskController controller;
    return handleControllerRequest(controller, request);
}

HttpResponse ControllerRegistry::handleUserRoute(const HttpRequest& request)
{
    UserController controller;
    return handleControllerRequest(controller, request);
}

HttpResponse ControllerRegistry::handleControllerRequest(IController& controller, const HttpRequest& request)
{
    const std::string& method = request.getMethod();

    if (!controller.supportsMethod(method))
    {
        return handleMethodNotAllowed();
    }

    if (method == "GET")
        return controller.handleGet(request);
    else if (method == "POST")
        return controller.handlePost(request);
    else if (method == "DELETE")
        return controller.handleDelete(request);
    else
        return handleMethodNotAllowed();
}

HttpResponse ControllerRegistry::handleNotFound()
{
    HttpResponse response;
    response.setStatus(404, "Not Found");
    response.setHeader("Content-Type", "text/plain");
    response.setBody("No controller found for this route");
    return response;
}

HttpResponse ControllerRegistry::handleMethodNotAllowed()
{
    return MethodNotAllowedHttpResponse("HTTP method not supported");
}

bool ControllerRegistry::matchesRoute(const std::string& url, const std::string& routePrefix) const
{
    return url.find(routePrefix) == 0;
}
