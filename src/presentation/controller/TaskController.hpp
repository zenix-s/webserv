#ifndef TASK_CONTROLLER_HPP
#define TASK_CONTROLLER_HPP

#include "../../core/HttpRequest.hpp"
#include "../../core/HttpResponse.hpp"

/**
 * Simple controller for the "/task" route.
 * Handles GET, POST and DELETE requests for tasks.
 */
class TaskController
{
  public:
    // Canonical form
    TaskController();
    TaskController(const TaskController& other);
    TaskController& operator=(const TaskController& other);
    ~TaskController();

    // Methods to handle HTTP requests
    HttpResponse handleGet(const HttpRequest& request);
    HttpResponse handlePost(const HttpRequest& request);
    HttpResponse handleDelete(const HttpRequest& request);
};

#endif // TASK_CONTROLLER_HPP