#include "TaskController.hpp"
#include "../../core/responses/OkHttpResponse.hpp"
#include <sstream>

TaskController::TaskController() : AController("/task")
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

bool TaskController::supportsMethod(const std::string& method) const
{
    return (method == "GET" || method == "POST" || method == "DELETE");
}
