#include "TaskController.hpp"
#include "../../core/responses/OkHttpResponse.hpp"
#include <sstream>

TaskController::TaskController() : AController()
{
}

TaskController::TaskController(const TaskController& other) : AController(other)
{
    (void)other;
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
    (void)request;
    return createNotImplementedResponse();
}

HttpResponse TaskController::handleDelete(const HttpRequest& request)
{
    (void)request;
    return createNotImplementedResponse();
}

bool TaskController::supportsMethod(const std::string& method) const
{
    return (method == "GET" || method == "POST" || method == "DELETE");
}
