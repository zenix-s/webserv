#include "TaskController.hpp"
#include "../../core/responses/OkHttpResponse.hpp"
#include <sstream>

TaskController::TaskController() : AController()
{
}

TaskController::TaskController(const TaskController& other) : AController(other)
{
    (void)other; // No additional state to copy
}

TaskController& TaskController::operator=(const TaskController& other)
{
    if (this != &other)
    {
        AController::operator=(other);
    }
    return *this;
}

TaskController::~TaskController()
{
}

HttpResponse TaskController::handleGet(const HttpRequest& request)
{
    // Simple implementation for GET /task
    std::stringstream body;
    body << "<html><body>"
         << "<h1>Task List</h1>"
         << "<p>This is a simple task controller.</p>"
         << "<p>Request URL: " << request.getUrl() << "</p>"
         << "</body></html>";

    return OkHttpResponse(body.str(), "text/html");
}

HttpResponse TaskController::handlePost(const HttpRequest& request)
{
    // Minimal implementation for POST
    (void)request; // Unused parameter
    return createNotImplementedResponse();
}

HttpResponse TaskController::handleDelete(const HttpRequest& request)
{
    // Minimal implementation for DELETE
    (void)request; // Unused parameter
    return createNotImplementedResponse();
}

bool TaskController::supportsMethod(const std::string& method) const
{
    return (method == "GET" || method == "POST" || method == "DELETE");
}