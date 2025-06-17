#ifndef HTTP_REQUEST_HANDLER_HPP
#define HTTP_REQUEST_HANDLER_HPP

#include "presentation/controller/ControllerRegistry.hpp"

class HttpRequest;
class HttpResponse;
class BadRequestHttpResponse;

/**
 * Simplified HTTP request handler that validates requests and delegates
 * to the controller registry for processing.
 */
class HttpRequestHandler
{
  private:
    ControllerRegistry _registry;

    // Helper method for invalid requests
    HttpResponse createBadRequestResponse();

  public:
    // Canonical form
    HttpRequestHandler();
    HttpRequestHandler(const HttpRequestHandler& other);
    HttpRequestHandler& operator=(const HttpRequestHandler& other);
    ~HttpRequestHandler();

    // Main method to handle HTTP requests
    HttpResponse handle(const HttpRequest& request);
};

#endif
