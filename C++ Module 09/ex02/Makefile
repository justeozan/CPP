.DEFAULT_GOAL = all

NAME = PmergeMe

SRC		=	main.cpp \
			PmergeMe.cpp

OBJ		=	$(patsubst %.cpp, obj/%.o, $(SRC))

CFLAGS	=	-Werror -Wall -Wextra -std=c++98
CC		=	c++ $(CFLAGS)
RM		=	rm -rf
INC		=	-Iincludes
OBJ_DIR	=	obj

$(NAME): $(OBJ)
	$(CC) $(INC) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o:	%.cpp Makefile PmergeMe.hpp
	@mkdir -p $(@D)
	@$(CC) $(INC) -c $< -o $@

simple:
	@clear
	@make all -s
	./$(NAME)
	@make clean -s

all:	$(NAME)

clean:
	$(RM) $(OBJ)
	$(RM) $(OBJ_DIR)

fclean:	clean
	$(RM) $(NAME)

re:		fclean simple

.PHONY:	simple all clean fclean re