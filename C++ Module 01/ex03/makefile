.DEFAULT_GOAL := simple

NAME	=	attack

SRC		=	src/main.cpp\
			src/HumanA.cpp\
			src/HumanB.cpp\
			src/Weapon.cpp

OBJ		=	$(patsubst src/%.cpp, obj/%.o, $(SRC))

CFLAGS	=	-Werror -Wall -Wextra -std=c++98
CC		=	c++ $(CFLAGS)
RM		=	rm -rf

$(NAME): $(OBJ)
	$(CC) $(OBJ) -Iinlcudes -o $(NAME) 

obj/%.o:	src/%.cpp makefile
	mkdir -p $(@D)
	$(CC) $(INC) -c $< -o $@

simple:
	@clear
	@make all -s
	@valgrind ./attack
	@make fclean -s

all:	$(NAME)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:		fclean all

.PHONY:	simple all clean fclean re