# Makefile para compilar el servidor HTTP modular en C++98

NAME    := webserv

COMPILER     := c++
FLAGS := -Wall -Wextra -Werror -std=c++98

SRCS    := src/main.cpp \
           src/core/HttpServer.cpp \
           src/core/HttpRequest.cpp \
           src/core/HttpResponse.cpp \
           src/HttpRequestHandler.cpp \
           src/presentation/controller/ControllerRegistry.cpp \
           src/presentation/controller/TaskController.cpp \
           src/presentation/controller/abstractions/AController.cpp \

OBJS    := $(SRCS:.cpp=.o)
DEPS    := $(SRCS:.cpp=.d)

all: $(NAME)

$(NAME): $(OBJS)
	$(COMPILER) $(FLAGS) -o $@ $(OBJS)

%.o: %.cpp
	$(COMPILER) $(FLAGS) -MMD -c $< -o $@

-include $(DEPS)

clean:
	rm -f $(OBJS) $(DEPS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
