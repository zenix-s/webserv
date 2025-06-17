#ifndef ACONTROLLER_HPP
#define ACONTROLLER_HPP

#include "IController.hpp"

/**
 * Abstract base controller class that provides default implementations
 * for HTTP methods and common functionality.
 * Controllers can inherit from this class and override only the methods they need.
 */
class AController : public IController
{
  public:
    // Virtual destructor
    virtual ~AController();

    // Default implementations that return "Method Not Allowed"
    virtual HttpResponse handleGet(const HttpRequest& request);
    virtual HttpResponse handlePost(const HttpRequest& request);
    virtual HttpResponse handleDelete(const HttpRequest& request);

    // Default implementation checks for standard methods
    virtual bool supportsMethod(const std::string& method) const;

  protected:
    // Protected constructor - only derived classes can instantiate
    AController();
    AController(const AController& other);
    AController& operator=(const AController& other);

    // Helper methods for common responses
    HttpResponse createMethodNotAllowedResponse() const;
    HttpResponse createNotImplementedResponse() const;
};

#endif // ACONTROLLER_HPP
