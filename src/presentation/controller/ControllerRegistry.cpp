#include "ControllerRegistry.hpp"
#include "TaskController.hpp"
#include "UserController.hpp"
#include "IController.hpp"

// Constructor
ControllerRegistry::ControllerRegistry()
{
}

// Copy constructor
ControllerRegistry::ControllerRegistry(const ControllerRegistry& other)
{
    (void)other; // No state to copy
}

// Assignment operator
ControllerRegistry& ControllerRegistry::operator=(const ControllerRegistry& other)
{
    (void)other; // No state to copy
    return *this;
}

// Destructor
ControllerRegistry::~ControllerRegistry()
{
}

// Main request processing method
HttpResponse ControllerRegistry::processRequest(const HttpRequest& request)
{
    const std::string& url = request.getUrl();

    // Route to appropriate handler
    if (matchesRoute(url, "/task"))
    {
        return handleTaskRoute(request);
    }
    else if (matchesRoute(url, "/user"))
    {
        return handleUserRoute(request);
    }

    // No matching route found
    return handleNotFound();
}

// Handle /task route
HttpResponse ControllerRegistry::handleTaskRoute(const HttpRequest& request)
{
    TaskController controller;
    return handleControllerRequest(controller, request);
}

// Handle /user route
HttpResponse ControllerRegistry::handleUserRoute(const HttpRequest& request)
{
    UserController controller;
    return handleControllerRequest(controller, request);
}

// Generic method to handle requests using controller interface
HttpResponse ControllerRegistry::handleControllerRequest(IController& controller, const HttpRequest& request)
{
    const std::string& method = request.getMethod();

    // Check if the controller supports this method
    if (!controller.supportsMethod(method))
    {
        return handleMethodNotAllowed();
    }

    // Route to appropriate handler method
    if (method == "GET")
    {
        return controller.handleGet(request);
    }
    else if (method == "POST")
    {
        return controller.handlePost(request);
    }
    else if (method == "DELETE")
    {
        return controller.handleDelete(request);
    }
    else
    {
        return handleMethodNotAllowed();
    }
}

// Handle 404 Not Found
HttpResponse ControllerRegistry::handleNotFound()
{
    HttpResponse response;
    response.setStatus(404, "Not Found");
    response.setHeader("Content-Type", "text/plain");
    response.setBody("No controller found for this route");
    return response;
}

// Handle 405 Method Not Allowed
HttpResponse ControllerRegistry::handleMethodNotAllowed()
{
    HttpResponse response;
    response.setStatus(405, "Method Not Allowed");
    response.setHeader("Content-Type", "text/plain");
    response.setBody("HTTP method not supported");
    return response;
}

// Helper method to check if URL matches a route prefix
bool ControllerRegistry::matchesRoute(const std::string& url, const std::string& routePrefix) const
{
    return url.find(routePrefix) == 0;
}