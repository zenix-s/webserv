#ifndef TASK_CONTROLLER_HPP
#define TASK_CONTROLLER_HPP

#include "AController.hpp"

/**
 * Simple controller for the "/task" route.
 * Handles GET, POST and DELETE requests for tasks.
 */
class TaskController : public AController
{
  public:
    // Canonical form
    TaskController();
    TaskController(const TaskController& other);
    TaskController& operator=(const TaskController& other);
    virtual ~TaskController();

    // Override methods from AController
    virtual HttpResponse handleGet(const HttpRequest& request);
    virtual HttpResponse handlePost(const HttpRequest& request);
    virtual HttpResponse handleDelete(const HttpRequest& request);
    
    // Override method support check
    virtual bool supportsMethod(const std::string& method) const;
};

#endif // TASK_CONTROLLER_HPP