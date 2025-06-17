#ifndef TASK_CONTROLLER_HPP
#define TASK_CONTROLLER_HPP

#include "abstractions/AController.hpp"

/**
 * Controlador para la ruta "/task".
 * Implementa el manejo de solicitudes GET, POST y DELETE para tareas.
 */
class TaskController : public AController
{
  public:
    // Canonical form
    TaskController();
    TaskController(const TaskController& other);
    TaskController& operator=(const TaskController& other);
    virtual ~TaskController();

    // Métodos para manejar solicitudes HTTP
    virtual HttpResponse handleGet(const HttpRequest& request);
    virtual HttpResponse handlePost(const HttpRequest& request);
    virtual HttpResponse handleDelete(const HttpRequest& request);
};

#endif // TASK_CONTROLLER_HPP
