.DEFAULT_GOAL := simple

NAME	=	brain

SRC		=	main.cpp

OBJ		=	$(patsubst %.cpp, %.o, $(SRC))

# Controls
CFLAGS	=	-Werror -Wall -Wextra -std=c++98
CC		=	c++ $(CFLAGS)
RM		=	rm -rf

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) 

%.o:	%.cpp makefile
	$(CC) $(INC) -c $< -o $@

simple:
	@clear
	@make all -s
	@valgrind ./brain
	@make fclean -s

all:	$(NAME)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:		fclean all

.PHONY:	simple all clean fclean re