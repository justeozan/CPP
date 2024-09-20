.DEFAULT_GOAL = all

NAME	=	animal

SRC_DIR	=	src
SRC		=	src/main.cpp\
			src/Animal.cpp\
			src/Cat.cpp\
			src/Dog.cpp\
			src/WrongAnimal.cpp\
			src/WrongCat.cpp

OBJ_DIR	=	.obj
OBJ		=	$(patsubst src/%.cpp, $(OBJ_DIR)/%.o, $(SRC))

CFLAGS	=	-Werror -Wall -Wextra -std=c++98
CC		=	c++ $(CFLAGS)
RM		=	rm -rf

INC		=	-Iincludes
I		=	includes/Animal.hpp \
			includes/Cat.hpp \
			includes/Dog.hpp \
			includes/WrongAnimal.hpp \
			includes/WrongCat.hpp

$(NAME): $(OBJ)
	$(CC) $(INC) $(OBJ) -o $(NAME) 

$(OBJ_DIR)/%.o:	src/%.cpp makefile $(I)
	@mkdir -p $(@D)
	$(CC) $(INC) -c $< -o $@

simple:
	@clear
	@make all -s
	./animal
	@make fclean -s

all:	$(NAME)

clean:
	$(RM) $(OBJ)
	$(RM) $(OBJ_DIR)

fclean:	clean
	$(RM) $(NAME)

re:		fclean all

.PHONY:	simple all clean fclean re