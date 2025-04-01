.DEFAULT_GOAL = all

NAME = iter

#color 
RESET   = "\033[0m"
RED     = "\033[31m"
GREEN   = "\033[32m"
YELLOW  = "\033[33m"
BLUE    = "\033[34m"
MAGENTA = "\033[35m"
CYAN    = "\033[36m"
WHITE   = "\033[37m"
BOLD    = "\033[1m"

SRC		=	main.cpp\

OBJ		=	$(patsubst %.cpp, obj/%.o, $(SRC))

CFLAGS	=	-Werror -Wall -Wextra -std=c++98
CC		=	c++ $(CFLAGS)
RM		=	rm -rf
INC		=	-Iincludes
OBJ_DIR	=	obj

$(NAME): $(OBJ)
	$(CC) $(INC) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o:	%.cpp Makefile iter.hpp
	@mkdir -p $(@D)
	@$(CC) $(INC) -c $< -o $@

simple:
	@clear
	@make all -s
	./$(NAME)

all:	$(NAME)

clean:
	$(RM) $(OBJ)
	$(RM) $(OBJ_DIR)

fclean:	clean
	$(RM) $(NAME)

re:		fclean simple

.PHONY:	simple all clean fclean re