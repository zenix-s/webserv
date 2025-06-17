#ifndef OK_HTTP_RESPONSE_HPP
#define OK_HTTP_RESPONSE_HPP

#include "../HttpResponse.hpp"

/**
 * Specialized HTTP response for successful requests (200 OK).
 * Inherits from HttpResponse and provides convenient constructors
 * for common success scenarios.
 */
class OkHttpResponse : public HttpResponse
{
  public:
    // Canonical form
    OkHttpResponse();
    OkHttpResponse(const std::string& body);
    OkHttpResponse(const std::string& body, const std::string& contentType);
    OkHttpResponse(const OkHttpResponse& other);
    OkHttpResponse& operator=(const OkHttpResponse& other);
    ~OkHttpResponse();
};

#endif // OK_HTTP_RESPONSE_HPP