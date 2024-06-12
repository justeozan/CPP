.DEFAULT: all

NAME	=	phonebook
CC		=	c++
CFLAGS	=	-Werror -Wall -Wextra -std=c++98
RM		=	rm -rf

SRC		=	phonebook.cpp

OBJ		=	$(NAME:.cpp=.o)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

%.o:	%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

all:	$(NAME)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:		fclean all

.PHONY:	all clean fclean re