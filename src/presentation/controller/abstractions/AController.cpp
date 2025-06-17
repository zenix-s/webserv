#include "AController.hpp"

AController::AController(const std::string& route) : _route(route)
{
}

AController::AController(const AController& other) : _route(other._route)
{
}

AController::~AController()
{
}

const std::string& AController::getRoute() const
{
    return _route;
}
