CC = c++
CFLAGS = -Wall -Wextra -Werror

# Executable name
NAME = fixed

# Source files
SRCS = Fixed.cpp main.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Targets
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

# Compile source files to object files
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re