#include "ControllerRegistry.hpp"
#include "TaskController.hpp"

// Constructor: registra los controladores disponibles
ControllerRegistry::ControllerRegistry()
{
    registerControllers();
}

// Constructor de copia
ControllerRegistry::ControllerRegistry(const ControllerRegistry& other)
{
    // Copia profunda de los controladores
    _controllers.reserve(other._controllers.size());
    for (size_t i = 0; i < other._controllers.size(); ++i)
    {
        // Solo tenemos TaskController, pero si hay más, aquí se debe clonar apropiadamente
        AController* original = other._controllers[i];
        if (original->getRoute() == "/task")
            _controllers.push_back(new TaskController(*static_cast<TaskController*>(original)));
        // Agregar aquí otros controladores si existen
    }
}

// Operador de asignación
ControllerRegistry& ControllerRegistry::operator=(const ControllerRegistry& other)
{
    if (this != &other)
    {
        // Liberar controladores actuales
        for (size_t i = 0; i < _controllers.size(); ++i)
            delete _controllers[i];
        _controllers.clear();

        // Copiar controladores del otro objeto
        _controllers.reserve(other._controllers.size());
        for (size_t i = 0; i < other._controllers.size(); ++i)
        {
            AController* orig = other._controllers[i];
            if (orig->getRoute() == "/task")
                _controllers.push_back(new TaskController(*static_cast<TaskController*>(orig)));
            // Agregar aquí otros controladores si existen
        }
    }
    return *this;
}

// Destructor: libera la memoria de los controladores
ControllerRegistry::~ControllerRegistry()
{
    for (size_t i = 0; i < _controllers.size(); ++i)
        delete _controllers[i];
    _controllers.clear();
}

// Registra todos los controladores disponibles
void ControllerRegistry::registerControllers()
{
    // Si ya hay controladores registrados, no volver a registrar
    if (!_controllers.empty())
        return;
    _controllers.push_back(new TaskController());
    // Aquí se pueden agregar más controladores en el futuro
}

// Busca el controlador correspondiente a la ruta solicitada
AController* ControllerRegistry::findController(const std::string& route) const
{
    for (size_t i = 0; i < _controllers.size(); ++i)
    {
        // Coincidencia exacta de la ruta base
        if (route.find(_controllers[i]->getRoute()) == 0)
            return _controllers[i];
    }
    return NULL;
}

// Procesa una solicitud encontrando el controlador adecuado
HttpResponse ControllerRegistry::processRequest(const HttpRequest& request)
{
    AController* controller = findController(request.getUrl());

    if (!controller)
    {
        HttpResponse response;
        response.setStatus(404, "Not Found");
        response.setHeader("Content-Type", "text/plain");
        response.setBody("No controller found for this route");
        return response;
    }

    const std::string& method = request.getMethod();
    if (method == "GET")
    {
        return controller->handleGet(request);
    }
    else if (method == "POST")
    {
        return controller->handlePost(request);
    }
    else if (method == "DELETE")
    {
        return controller->handleDelete(request);
    }
    else
    {
        HttpResponse response;
        response.setStatus(405, "Method Not Allowed");
        response.setHeader("Content-Type", "text/plain");
        response.setBody("HTTP method not supported");
        return response;
    }
}
