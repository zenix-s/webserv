#ifndef BAD_REQUEST_HTTP_RESPONSE_HPP
#define BAD_REQUEST_HTTP_RESPONSE_HPP

#include "../HttpResponse.hpp"

/**
 * Specialized HTTP response for bad requests (400 Bad Request).
 * Inherits from HttpResponse and provides convenient constructors
 * for common error scenarios.
 */
class BadRequestHttpResponse : public HttpResponse
{
  public:
    // Canonical form
    BadRequestHttpResponse();
    BadRequestHttpResponse(const std::string& body);
    BadRequestHttpResponse(const std::string& body, const std::string& contentType);
    BadRequestHttpResponse(const BadRequestHttpResponse& other);
    BadRequestHttpResponse& operator=(const BadRequestHttpResponse& other);
    ~BadRequestHttpResponse();
};

#endif // BAD_REQUEST_HTTP_RESPONSE_HPP