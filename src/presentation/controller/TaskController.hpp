#ifndef TASK_CONTROLLER_HPP
#define TASK_CONTROLLER_HPP

#include "AController.hpp"

class TaskController : public AController
{
  public:
    TaskController();
    TaskController(const TaskController& other);
    TaskController& operator=(const TaskController& other);
    virtual ~TaskController();

    virtual HttpResponse handleGet(const HttpRequest& request);

    virtual bool supportsMethod(const std::string& method) const;
};

#endif
