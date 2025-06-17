#ifndef OK_HTTP_RESPONSE_HPP
#define OK_HTTP_RESPONSE_HPP

#include "../HttpResponse.hpp"

class OkHttpResponse : public HttpResponse
{
  public:
    OkHttpResponse();
    OkHttpResponse(const std::string& body);
    OkHttpResponse(const std::string& body, const std::string& contentType);
    OkHttpResponse(const OkHttpResponse& other);
    OkHttpResponse& operator=(const OkHttpResponse& other);
    ~OkHttpResponse();
};

#endif
