#ifndef HTTPREQUEST_HPP
#define HTTPREQUEST_HPP

#include <string>

class HttpRequest
{
  private:
    std::string method;
    std::string url;
    std::string version;
    std::string raw;
    bool        valid;

    void parse(const char* raw_request);

  public:
    // Canonical form
    HttpRequest(const char* raw_request);
    HttpRequest(const HttpRequest& other);
    HttpRequest& operator=(const HttpRequest& other);
    ~HttpRequest();

    // Métodos de acceso
    const std::string& getMethod() const;
    const std::string& getUrl() const;
    const std::string& getVersion() const;
    const std::string& getRaw() const;

    // Indica si el parseo fue exitoso
    bool isValid() const;
};

#endif // HTTPREQUEST_HPP
