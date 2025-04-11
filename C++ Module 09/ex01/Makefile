.DEFAULT_GOAL = all

NAME = RPN

SRC		=	main.cpp\
			RPN.cpp

OBJ		=	$(patsubst %.cpp, obj/%.o, $(SRC))

CFLAGS	=	-Werror -Wall -Wextra -std=c++98
CC		=	c++ $(CFLAGS)
RM		=	rm -rf
INC		=	-Iincludes
OBJ_DIR	=	obj

$(NAME): $(OBJ)
	$(CC) $(INC) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o:	%.cpp Makefile RPN.hpp
	@mkdir -p $(@D)
	@$(CC) $(INC) -c $< -o $@

simple:
	@clear
	@make all -s
	./$(NAME) "8 9 * 9 - 9 - 9 - 4 - 1 +"
	./$(NAME) "7 7 * 7 -"
	./$(NAME) "1 2 * 2 / 2 * 2 4 - +"
	./$(NAME) "           0                  5                      /               "
	./$(NAME) "(1 + 1)"
	./$(NAME) "(81 9 *)"
	./$(NAME) "5 0 /"
	./$(NAME) "/ 4 0"
	./$(NAME) "5 j +"
	@make clean -s

all:	$(NAME)

clean:
	$(RM) $(OBJ)
	$(RM) $(OBJ_DIR)

fclean:	clean
	$(RM) $(NAME)

re:		fclean simple

.PHONY:	simple all clean fclean re