#include "TaskController.hpp"
#include <sstream>

TaskController::TaskController() : AController("/task")
{
}

TaskController::TaskController(const TaskController& other) : AController(other._route)
{
}

TaskController& TaskController::operator=(const TaskController& other)
{
    if (this != &other)
    {
        _route = other._route;
    }
    return *this;
}

TaskController::~TaskController()
{
}

HttpResponse TaskController::handleGet(const HttpRequest& request)
{
    HttpResponse response;
    // Simple implementation for GET /task
    response.setStatus(200, "OK");
    response.setHeader("Content-Type", "text/html");

    std::stringstream body;
    body << "<html><body>"
         << "<h1>Task List</h1>"
         << "<p>This is a simple task controller.</p>"
         << "<p>Request URL: " << request.getUrl() << "</p>"
         << "</body></html>";

    response.setBody(body.str());

    return response;
}

HttpResponse TaskController::handlePost(const HttpRequest& request)
{
    HttpResponse response;
    // Minimal implementation for POST
    (void)request; // Unused parameter
    response.setStatus(501, "Not Implemented");
    response.setHeader("Content-Type", "text/plain");
    response.setBody("POST method not implemented yet");

    return response;
}

HttpResponse TaskController::handleDelete(const HttpRequest& request)
{
    HttpResponse response;
    // Minimal implementation for DELETE
    (void)request; // Unused parameter
    response.setStatus(501, "Not Implemented");
    response.setHeader("Content-Type", "text/plain");
    response.setBody("DELETE method not implemented yet");

    return response;
}
