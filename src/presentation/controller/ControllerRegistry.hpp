#ifndef CONTROLLER_REGISTRY_HPP
#define CONTROLLER_REGISTRY_HPP

#include "../../core/HttpRequest.hpp"
#include "../../core/HttpResponse.hpp"
#include "IController.hpp"
#include <string>

class ControllerRegistry
{
  public:
    ControllerRegistry();
    ControllerRegistry(const ControllerRegistry& other);
    ControllerRegistry& operator=(const ControllerRegistry& other);
    ~ControllerRegistry();

    HttpResponse processRequest(const HttpRequest& request);

  private:
    HttpResponse handleTaskRoute(const HttpRequest& request);
    HttpResponse handleUserRoute(const HttpRequest& request);
    HttpResponse handleNotFound();
    HttpResponse handleMethodNotAllowed();

    bool matchesRoute(const std::string& url, const std::string& routePrefix) const;

    HttpResponse handleControllerRequest(IController& controller, const HttpRequest& request);
};

#endif
