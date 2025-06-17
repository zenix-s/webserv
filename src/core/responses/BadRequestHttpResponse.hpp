#ifndef BAD_REQUEST_HTTP_RESPONSE_HPP
#define BAD_REQUEST_HTTP_RESPONSE_HPP

#include "../HttpResponse.hpp"

class BadRequestHttpResponse : public HttpResponse
{
  public:
    BadRequestHttpResponse();
    BadRequestHttpResponse(const std::string& body);
    BadRequestHttpResponse(const std::string& body, const std::string& contentType);
    BadRequestHttpResponse(const BadRequestHttpResponse& other);
    BadRequestHttpResponse& operator=(const BadRequestHttpResponse& other);
    ~BadRequestHttpResponse();
};

#endif
