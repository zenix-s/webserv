#ifndef ICONTROLLER_HPP
#define ICONTROLLER_HPP

#include "../../core/HttpRequest.hpp"
#include "../../core/HttpResponse.hpp"

/**
 * Abstract interface for HTTP controllers.
 * Defines the contract that all controllers must implement
 * to handle different HTTP methods.
 */
class IController
{
  public:
    // Virtual destructor for proper cleanup
    virtual ~IController() {}

    // Pure virtual methods for HTTP method handling
    virtual HttpResponse handleGet(const HttpRequest& request) = 0;
    virtual HttpResponse handlePost(const HttpRequest& request) = 0;
    virtual HttpResponse handleDelete(const HttpRequest& request) = 0;

    // Optional method to check if a specific HTTP method is supported
    virtual bool supportsMethod(const std::string& method) const = 0;
};

#endif // ICONTROLLER_HPP