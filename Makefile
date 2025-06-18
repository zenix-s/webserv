

NAME    := webserv

COMPILER := c++
FLAGS    := -Wall -Wextra -Werror -std=c++98

SRCS    :=	./src/main.cpp \
			./src/server/HttpServer.cpp \
			./src/http/HttpRequest.cpp \
			./src/http/HttpResponse.cpp \
			./src/http/HttpRequestHandler.cpp \
			./src/controllers/base/AController.cpp \
			./src/controllers/ControllerRegistry.cpp \
			./src/controllers/TaskController.cpp \
			./src/controllers/UserController.cpp \


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
