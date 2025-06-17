#ifndef HTTP_REQUEST_HANDLER_HPP
#define HTTP_REQUEST_HANDLER_HPP

#include "presentation/controller/ControllerRegistry.hpp"

class HttpRequest;
class HttpResponse;

/**
 * Clase encargada de manejar una solicitud HTTP y generar la respuesta correspondiente.
 * Utiliza ControllerRegistry para dirigir las solicitudes a los controladores adecuados.
 */
class HttpRequestHandler
{
  private:
    // Registro de controladores disponibles
    ControllerRegistry _controllerRegistry;

    // Métodos auxiliares para procesar solicitudes inválidas
    void handleBadRequest(HttpResponse& response);

  public:
    // Canonical form
    HttpRequestHandler();
    HttpRequestHandler(const HttpRequestHandler& other);
    HttpRequestHandler& operator=(const HttpRequestHandler& other);
    ~HttpRequestHandler();

    // Procesa la solicitud y genera la respuesta.
    HttpResponse handle(const HttpRequest& request);
};

#endif // HTTP_REQUEST_HANDLER_HPP
