#ifndef NOT_IMPLEMENTED_HTTP_RESPONSE_HPP
#define NOT_IMPLEMENTED_HTTP_RESPONSE_HPP

#include "../HttpResponse.hpp"

/**
 * Specialized HTTP response for not implemented requests (501 Not Implemented).
 * Inherits from HttpResponse and provides convenient constructors
 * for common not implemented scenarios.
 */
class NotImplementedHttpResponse : public HttpResponse
{
  public:
    // Canonical form
    NotImplementedHttpResponse();
    NotImplementedHttpResponse(const std::string& body);
    NotImplementedHttpResponse(const std::string& body, const std::string& contentType);
    NotImplementedHttpResponse(const NotImplementedHttpResponse& other);
    NotImplementedHttpResponse& operator=(const NotImplementedHttpResponse& other);
    ~NotImplementedHttpResponse();
};

#endif // NOT_IMPLEMENTED_HTTP_RESPONSE_HPP