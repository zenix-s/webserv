#include "TaskController.hpp"
#include "../../core/responses/OkHttpResponse.hpp"
#include <sstream>

TaskController::TaskController()
{
}

TaskController::TaskController(const TaskController& other)
{
    (void)other; // No state to copy
}

TaskController& TaskController::operator=(const TaskController& other)
{
    (void)other; // No state to copy
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