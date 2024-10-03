.DEFAULT_GOAL = all

NAME	=	DiamondTrap

SRC_DIR	=	src
SRC		=	src/main.cpp\
			src/ClapTrap.cpp\
			src/ScavTrap.cpp\
			src/FragTrap.cpp\
			src/DiamondTrap.cpp

OBJ_DIR	=	obj
OBJ		=	$(patsubst src/%.cpp, obj/%.o, $(SRC))

# Controls
CFLAGS	=	-Werror -Wall -Wextra -std=c++98
CC		=	c++ $(CFLAGS)
RM		=	rm -rf
INC		=	-Iincludes

$(NAME): $(OBJ)
	$(CC) $(INC) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o:	src/%.cpp makefile includes/ClapTrap.hpp includes/ScavTrap.hpp includes/FragTrap.hpp includes/DiamondTrap.hpp
	@mkdir -p $(@D)
	$(CC) $(INC) -c $< -o $@

simple:
	@clear
	@make all -s
	./DiamondTrap
	@make fclean -s

all:	$(NAME)

clean:
	$(RM) $(OBJ)
	$(RM) $(OBJ_DIR)

fclean:	clean
	$(RM) $(NAME)

re:		fclean all

.PHONY:	simple all clean fclean re