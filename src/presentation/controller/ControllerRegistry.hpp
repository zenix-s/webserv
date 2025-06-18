#ifndef CONTROLLER_REGISTRY_HPP
#define CONTROLLER_REGISTRY_HPP

#include "../../core/HttpRequest.hpp"
#include "../../core/HttpResponse.hpp"
#include "AController.hpp"
#include "IController.hpp"
#include <string>
#include <vector>

class ControllerRegistry
{
  private:
    std::vector<AController*> _controllers;

    HttpResponse handleNotFound();

    bool matchesRoute(const std::string& url, const std::string& routePrefix) const;

    HttpResponse handleControllerRequest(IController& controller, const HttpRequest& request);

  public:
    ControllerRegistry();
    ControllerRegistry(const ControllerRegistry& other);
    ControllerRegistry& operator=(const ControllerRegistry& other);
    ~ControllerRegistry();

    HttpResponse processRequest(const HttpRequest& request);
};

#endif
