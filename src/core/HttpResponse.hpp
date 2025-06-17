#ifndef HTTPRESPONSE_HPP
#define HTTPRESPONSE_HPP

#include <string>

class HttpResponse
{
  private:
    int         _statusCode;
    std::string _reasonPhrase;
    std::string _body;
    std::string _headers;

    void updateContentLength();

  public:
    // Canonical form
    HttpResponse();
    HttpResponse(const HttpResponse& other);
    HttpResponse& operator=(const HttpResponse& other);
    ~HttpResponse();

    // Métodos principales
    void setStatus(int code, const std::string& reason);
    void setHeader(const std::string& key, const std::string& value);
    void setBody(const std::string& body);

    std::string toString() const;
};

#endif // HTTPRESPONSE_HPP
