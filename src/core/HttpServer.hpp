#ifndef HTTPSERVER_HPP
#define HTTPSERVER_HPP

#include <netdb.h>
#include <string>

class HttpRequestHandler;

class HttpServer
{
  private:
    std::string      _port;
    int              _server_fd;
    struct addrinfo* _res;

    // Inicializa el socket y lo enlaza al puerto
    bool setupSocket();

    // Acepta una conexión entrante y la maneja
    void handleClient();

    // Limpia recursos
    void cleanup();

  public:
    // Canonical form
    HttpServer(const std::string& port);
    HttpServer(const HttpServer& other);
    ~HttpServer();
    HttpServer& operator=(const HttpServer& other);

    // Inicia el bucle principal del servidor
    void run();
};

#endif // HTTPSERVER_HPP
