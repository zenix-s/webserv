#ifndef NOT_FOUND_HTTP_RESPONSE_HPP
#define NOT_FOUND_HTTP_RESPONSE_HPP

#include "../HttpResponse.hpp"

class NotFoundHttpResponse : public HttpResponse
{
  public:
    NotFoundHttpResponse();
    NotFoundHttpResponse(const std::string& body);
    NotFoundHttpResponse(const std::string& body, const std::string& contentType);
    NotFoundHttpResponse(const NotFoundHttpResponse& other);
    NotFoundHttpResponse& operator=(const NotFoundHttpResponse& other);
    ~NotFoundHttpResponse();
};
#endif
