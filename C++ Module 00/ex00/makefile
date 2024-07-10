NAME = megaphone
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -rf

SRC = megaphone.cpp

OBJ = $(SRC:.cpp=.o)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp
	@$(CC) $(CFLAGS) -c $< -o $@

all :	$(NAME)

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

