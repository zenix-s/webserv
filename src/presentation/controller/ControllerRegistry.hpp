#ifndef CONTROLLER_REGISTRY_HPP
#define CONTROLLER_REGISTRY_HPP

#include "../../core/HttpRequest.hpp"
#include "../../core/HttpResponse.hpp"
#include "abstractions/AController.hpp"
#include <string>
#include <vector>

/**
 * Registro de controladores que gestiona todos los controladores disponibles.
 * Facilita encontrar el controlador adecuado según la URL de la solicitud.
 */
class ControllerRegistry
{
  private:
    std::vector<AController*> _controllers;

    // Busca el controlador correspondiente a la ruta solicitada
    AController* findController(const std::string& route) const;

  public:
    // Canonical form
    ControllerRegistry();
    ControllerRegistry(const ControllerRegistry& other);
    ControllerRegistry& operator=(const ControllerRegistry& other);
    ~ControllerRegistry();

    // Registra todos los controladores disponibles
    void registerControllers();

    // Procesa una solicitud encontrando el controlador adecuado
    HttpResponse processRequest(const HttpRequest& request);
};

#endif // CONTROLLER_REGISTRY_HPP
