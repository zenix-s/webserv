#ifndef USER_CONTROLLER_HPP
#define USER_CONTROLLER_HPP

#include "AController.hpp"

/**
 * Controller for user-related operations.
 * Handles GET and POST requests for user management.
 * Demonstrates the use of AController abstraction.
 */
class UserController : public AController
{
  public:
    // Canonical form
    UserController();
    UserController(const UserController& other);
    UserController& operator=(const UserController& other);
    virtual ~UserController();

    // Override methods from AController
    virtual HttpResponse handleGet(const HttpRequest& request);
    virtual HttpResponse handlePost(const HttpRequest& request);
    
    // Override method support check
    virtual bool supportsMethod(const std::string& method) const;
};

#endif // USER_CONTROLLER_HPP