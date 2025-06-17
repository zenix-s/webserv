#ifndef METHOD_NOT_ALLOWED_HTTP_RESPONSE_HPP
#define METHOD_NOT_ALLOWED_HTTP_RESPONSE_HPP

#include "../HttpResponse.hpp"

class MethodNotAllowedHttpResponse : public HttpResponse
{
  public:
    MethodNotAllowedHttpResponse();
    MethodNotAllowedHttpResponse(const std::string& body);
    MethodNotAllowedHttpResponse(const std::string& body, const std::string& contentType);
    MethodNotAllowedHttpResponse(const MethodNotAllowedHttpResponse& other);
    MethodNotAllowedHttpResponse& operator=(const MethodNotAllowedHttpResponse& other);
    ~MethodNotAllowedHttpResponse();
};

#endif
