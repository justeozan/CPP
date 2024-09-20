.DEFAULT_GOAL = all

NAME	=	ClapTrap

SRC		=	src/main.cpp\
			src/ClapTrap.cpp

OBJ		=	$(patsubst src/%.cpp, obj/%.o, $(SRC))

CFLAGS	=	-Werror -Wall -Wextra -std=c++98
CC		=	c++ $(CFLAGS)
RM		=	rm -rf
INC		=	-Iincludes
SRC_DIR	=	src
OBJ_DIR	=	obj

$(NAME): $(OBJ)
	$(CC) $(INC) $(OBJ) -o $(NAME) 

$(OBJ_DIR)/%.o:	src/%.cpp makefile includes/ClapTrap.hpp
	@mkdir -p $(@D)
	$(CC) $(INC) -c $< -o $@

simple:
	@clear
	@make all -s
	./ClapTrap
	@make fclean -s

all:	$(NAME)

clean:
	$(RM) $(OBJ)
	$(RM) $(OBJ_DIR)

fclean:	clean
	$(RM) $(NAME)

re:		fclean all

.PHONY:	simple all clean fclean re