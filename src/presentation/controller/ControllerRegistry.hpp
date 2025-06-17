#ifndef CONTROLLER_REGISTRY_HPP
#define CONTROLLER_REGISTRY_HPP

#include "../../core/HttpRequest.hpp"
#include "../../core/HttpResponse.hpp"
#include <string>

/**
 * Simple registry that routes HTTP requests to appropriate handlers.
 * No dynamic memory allocation - creates controllers on demand.
 */
class ControllerRegistry
{
  public:
    // Canonical form
    ControllerRegistry();
    ControllerRegistry(const ControllerRegistry& other);
    ControllerRegistry& operator=(const ControllerRegistry& other);
    ~ControllerRegistry();

    // Main method to process requests
    HttpResponse processRequest(const HttpRequest& request);

  private:
    // Route-specific handlers
    HttpResponse handleTaskRoute(const HttpRequest& request);
    HttpResponse handleNotFound();
    HttpResponse handleMethodNotAllowed();

    // Helper method to match routes
    bool matchesRoute(const std::string& url, const std::string& routePrefix) const;
};

#endif // CONTROLLER_REGISTRY_HPP