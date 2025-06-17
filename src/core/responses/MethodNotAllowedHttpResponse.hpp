#ifndef METHOD_NOT_ALLOWED_HTTP_RESPONSE_HPP
#define METHOD_NOT_ALLOWED_HTTP_RESPONSE_HPP

#include "../HttpResponse.hpp"

/**
 * Specialized HTTP response for method not allowed requests (405 Method Not Allowed).
 * Inherits from HttpResponse and provides convenient constructors
 * for common method not allowed scenarios.
 */
class MethodNotAllowedHttpResponse : public HttpResponse
{
  public:
    // Canonical form
    MethodNotAllowedHttpResponse();
    MethodNotAllowedHttpResponse(const std::string& body);
    MethodNotAllowedHttpResponse(const std::string& body, const std::string& contentType);
    MethodNotAllowedHttpResponse(const MethodNotAllowedHttpResponse& other);
    MethodNotAllowedHttpResponse& operator=(const MethodNotAllowedHttpResponse& other);
    ~MethodNotAllowedHttpResponse();
};

#endif // METHOD_NOT_ALLOWED_HTTP_RESPONSE_HPP