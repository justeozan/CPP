.DEFAULT_GOAL: all

NAME	=	animal

SRC		=	src/main.cpp\
			src/Animal.cpp\
			src/Cat.cpp\
			src/Dog.cpp

OBJ		=	$(patsubst src/%.cpp, obj/%.o, $(SRC))
DEP		=	$(patsubst src/%.cpp, dep/%.o, $(SRC))

# Controls
CFLAGS	=	-Werror -Wall -Wextra -std=c++98
CC		=	c++ $(CFLAGS)
RM		=	rm -rf
I		=	includes
INC		=	-I$(I)
SRC_DIR	=	src
OBJ_DIR	=	obj

$(NAME): $(OBJ)
	$(CC) $(INC) $(OBJ) -o $(NAME) 

$(OBJ_DIR)/%.o:	src/%.cpp makefile
	@mkdir -p $(@D)
	$(CC) $(INC) -c $< -o $@

simple:
	@clear
	c++ src/*.cpp -Werror -Wextra -Wall -std=c++98 includes/Animal.hpp includes/Cat.hpp includes/Dog.hpp -o animal
	./animal
	@rm animal

all:	$(NAME)

clean:
	$(RM) $(OBJ)
	$(RM) $(OBJ_DIR)

fclean:	clean
	$(RM) $(NAME)

re:		fclean all

.PHONY:	all clean fclean re