# Makefile para compilar el servidor HTTP modular en C++98

NAME    := webserv

COMPILER     := c++
FLAGS := -Wall -Wextra -Werror -std=c++98

SRCS    := src/main.cpp \
           src/core/HttpServer.cpp \
           src/core/HttpRequest.cpp \
           src/core/HttpResponse.cpp \
           src/core/responses/OkHttpResponse.cpp \
           src/core/responses/BadRequestHttpResponse.cpp \
           src/core/responses/NotImplementedHttpResponse.cpp \
           src/core/responses/MethodNotAllowedHttpResponse.cpp \
           src/HttpRequestHandler.cpp \
           src/presentation/controller/ControllerRegistry.cpp \
           src/presentation/controller/AController.cpp \
           src/presentation/controller/TaskController.cpp \
           src/presentation/controller/UserController.cpp \

OBJS    := $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(COMPILER) $(FLAGS) -o $@ $(OBJS)

%.o: %.cpp
	$(COMPILER) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
