#ifndef CONTROLLER_ABSTRACTIONS_CONTROLLER_HPP
#define CONTROLLER_ABSTRACTIONS_CONTROLLER_HPP

#include "../../../core/HttpRequest.hpp"
#include "../../../core/HttpResponse.hpp"
#include <string>

/**
 * Interfaz base para controladores HTTP.
 * Cada controlador tiene una ruta base (por ejemplo, "/tarea") y métodos para manejar GET, POST y DELETE.
 */
class AController
{
  protected:
    std::string _route; // Ruta base del controlador, por ejemplo: "/tarea"

  public:
    // Constructor y destructor virtual
    AController(const std::string& route);
    AController(const AController& other);

    virtual ~AController();

    // Devuelve la ruta base del controlador
    const std::string& getRoute() const;

    // Métodos virtuales puros para manejar los distintos tipos de solicitudes HTTP
    virtual HttpResponse handleGet(const HttpRequest& request) = 0;
    virtual HttpResponse handlePost(const HttpRequest& request) = 0;
    virtual HttpResponse handleDelete(const HttpRequest& request) = 0;
};

#endif // CONTROLLER_ABSTRACTIONS_ICONTROLLER_HPP
