#include "UserController.hpp"
#include "../../core/responses/OkHttpResponse.hpp"
#include <sstream>

UserController::UserController() : AController()
{
}

UserController::UserController(const UserController& other) : AController(other)
{
    (void)other; // No additional state to copy
}

UserController& UserController::operator=(const UserController& other)
{
    if (this != &other)
    {
        AController::operator=(other);
    }
    return *this;
}

UserController::~UserController()
{
}

HttpResponse UserController::handleGet(const HttpRequest& request)
{
    std::stringstream body;
    body << "<html><body>"
         << "<h1>User Management</h1>"
         << "<p>List of users would be displayed here.</p>"
         << "<p>Request URL: " << request.getUrl() << "</p>"
         << "<p>Supported methods: GET, POST</p>"
         << "</body></html>";

    return OkHttpResponse(body.str(), "text/html");
}

HttpResponse UserController::handlePost(const HttpRequest& request)
{
    // Simple implementation for POST /user
    (void)request; // Unused parameter for now
    
    std::stringstream body;
    body << "<html><body>"
         << "<h1>User Created</h1>"
         << "<p>New user would be created here.</p>"
         << "<p>This is a demonstration of POST handling.</p>"
         << "</body></html>";

    return OkHttpResponse(body.str(), "text/html");
}

bool UserController::supportsMethod(const std::string& method) const
{
    return (method == "GET" || method == "POST");
}