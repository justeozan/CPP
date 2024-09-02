.DEFAULT_GOAL := simple

NAME	=	sed

SRC		=	main.cpp

OBJ		=	$(patsubst %.cpp, %.o, $(SRC))

CFLAGS	=	-Werror -Wall -Wextra -std=c++98
CC		=	c++ $(CFLAGS)
RM		=	rm -rf
I		=	-Iincludes
SRC_DIR	=	src
OBJ_DIR	=	obj

$(NAME): $(OBJ)
	$(CC) $(I) $(OBJ) -o $(NAME) 

$(OBJ_DIR)/%.o:	src/%.cpp makefile
	@mkdir -p $(@D)
	$(CC) $(I) -c $< -o $@

simple:
	@clear
	@make all -s
	@./sed test "est" "n'est pas"
	@echo "You've just replaced 'est' with 'n'est pas' in 'test.replace'"
	@make fclean -s

all:	$(NAME)

clean:
	$(RM) $(OBJ)
	$(RM) $(OBJ_DIR)

fclean:	clean
	$(RM) $(NAME)

re:		fclean all

.PHONY:	simple all clean fclean re