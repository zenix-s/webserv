# Controller Abstraction Design

This document describes the controller abstraction implemented in the webserv HTTP server project.

## Overview

The controller abstraction provides a clean, extensible way to handle HTTP requests using object-oriented design principles. It follows the Interface Segregation Principle and provides both an interface (`IController`) and an abstract base class (`AController`) for common functionality.

## Architecture

### IController Interface

The `IController` interface defines the contract that all controllers must implement:

```cpp
class IController
{
public:
    virtual ~IController() {}
    
    // Pure virtual methods for HTTP method handling
    virtual HttpResponse handleGet(const HttpRequest& request) = 0;
    virtual HttpResponse handlePost(const HttpRequest& request) = 0;
    virtual HttpResponse handleDelete(const HttpRequest& request) = 0;
    
    // Method to check if a specific HTTP method is supported
    virtual bool supportsMethod(const std::string& method) const = 0;
};
```

### AController Abstract Base Class

The `AController` class provides default implementations and common functionality:

- **Default Behavior**: Returns "405 Method Not Allowed" for all HTTP methods
- **Helper Methods**: Provides `createMethodNotAllowedResponse()` and `createNotImplementedResponse()`
- **Extensibility**: Controllers can inherit and override only the methods they need
- **Method Support**: Default implementation recognizes GET, POST, and DELETE methods

## Usage Examples

### TaskController Implementation

```cpp
class TaskController : public AController
{
public:
    // Override only the methods you need
    virtual HttpResponse handleGet(const HttpRequest& request);
    virtual HttpResponse handlePost(const HttpRequest& request);
    virtual HttpResponse handleDelete(const HttpRequest& request);
    
    // Specify which methods are supported
    virtual bool supportsMethod(const std::string& method) const;
};
```

### UserController Implementation

```cpp
class UserController : public AController
{
public:
    // Only implements GET and POST
    virtual HttpResponse handleGet(const HttpRequest& request);
    virtual HttpResponse handlePost(const HttpRequest& request);
    
    virtual bool supportsMethod(const std::string& method) const;
};
```

## Benefits

### 1. Consistency
- All controllers follow the same interface
- Standardized method signatures
- Predictable behavior for unsupported methods

### 2. Extensibility
- Easy to add new controllers
- Controllers only implement methods they need
- Common functionality provided by base class

### 3. Maintainability
- Single point of change for common controller behavior
- Clear separation of concerns
- Polymorphic handling in registry

### 4. Type Safety
- Compile-time checking of method signatures
- Interface ensures all required methods are implemented
- Virtual destructor ensures proper cleanup

## Integration with ControllerRegistry

The `ControllerRegistry` uses the abstraction to handle requests generically:

```cpp
HttpResponse ControllerRegistry::handleControllerRequest(IController& controller, const HttpRequest& request)
{
    const std::string& method = request.getMethod();
    
    // Check if the controller supports this method
    if (!controller.supportsMethod(method))
    {
        return handleMethodNotAllowed();
    }
    
    // Route to appropriate handler method
    if (method == "GET")
        return controller.handleGet(request);
    else if (method == "POST")
        return controller.handlePost(request);
    else if (method == "DELETE")
        return controller.handleDelete(request);
}
```

## File Structure

```
src/presentation/controller/
├── IController.hpp              # Interface definition
├── AController.hpp              # Abstract base class header
├── AController.cpp              # Abstract base class implementation
├── TaskController.hpp           # Task controller header
├── TaskController.cpp           # Task controller implementation
├── UserController.hpp           # User controller header (example)
├── UserController.cpp           # User controller implementation (example)
└── ControllerRegistry.hpp       # Registry using the abstraction
```

## Adding New Controllers

To add a new controller:

1. Create a new class inheriting from `AController`
2. Override the HTTP methods you want to support
3. Implement `supportsMethod()` to return true for supported methods
4. Add routing logic to `ControllerRegistry`
5. Add the source file to the Makefile

Example:
```cpp
class ApiController : public AController
{
public:
    virtual HttpResponse handleGet(const HttpRequest& request);
    virtual HttpResponse handlePost(const HttpRequest& request);
    virtual bool supportsMethod(const std::string& method) const;
};
```

## Supported HTTP Methods

The abstraction supports the three core HTTP methods:
- **GET**: For retrieving resources
- **POST**: For creating new resources
- **DELETE**: For removing resources

This focused approach keeps the interface simple while covering the most common web server operations.

## C++98 Compatibility

The design is fully compatible with C++98:
- Uses virtual inheritance properly
- Implements canonical form for all classes
- No modern C++ features required
- Compatible with strict compiler flags (-Wall -Wextra -Werror)

## Best Practices

1. **Always override `supportsMethod()`** to accurately reflect which methods your controller handles
2. **Use helper methods** from `AController` like `createNotImplementedResponse()` for consistency
3. **Follow the canonical form** (copy constructor, assignment operator, destructor)
4. **Keep controllers focused** on a single resource or related group of operations
5. **Use the specialized response classes** (`OkHttpResponse`, `BadRequestHttpResponse`) for cleaner code