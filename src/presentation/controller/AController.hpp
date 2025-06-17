#ifndef ACONTROLLER_HPP
#define ACONTROLLER_HPP

#include "IController.hpp"

class AController : public IController
{
  public:
    virtual ~AController();

    virtual HttpResponse handleGet(const HttpRequest& request);
    virtual HttpResponse handlePost(const HttpRequest& request);
    virtual HttpResponse handleDelete(const HttpRequest& request);

    virtual bool supportsMethod(const std::string& method) const;

  protected:
    AController();
    AController(const AController& other);
    AController& operator=(const AController& other);

    HttpResponse createMethodNotAllowedResponse() const;
    HttpResponse createNotImplementedResponse() const;
};

#endif
