#ifndef NOT_IMPLEMENTED_HTTP_RESPONSE_HPP
#define NOT_IMPLEMENTED_HTTP_RESPONSE_HPP

#include "../HttpResponse.hpp"

class NotImplementedHttpResponse : public HttpResponse
{
  public:
    NotImplementedHttpResponse();
    NotImplementedHttpResponse(const std::string& body);
    NotImplementedHttpResponse(const std::string& body, const std::string& contentType);
    NotImplementedHttpResponse(const NotImplementedHttpResponse& other);
    NotImplementedHttpResponse& operator=(const NotImplementedHttpResponse& other);
    ~NotImplementedHttpResponse();
};

#endif
