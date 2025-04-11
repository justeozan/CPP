.DEFAULT_GOAL = all

NAME = btc

SRC		=	main.cpp\
			BitcoinExchange.cpp

OBJ		=	$(patsubst %.cpp, obj/%.o, $(SRC))

CFLAGS	=	-Werror -Wall -Wextra -std=c++98
CC		=	c++ $(CFLAGS)
RM		=	rm -rf
INC		=	-Iincludes
OBJ_DIR	=	obj

$(NAME): $(OBJ)
	$(CC) $(INC) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o:	%.cpp Makefile
	@mkdir -p $(@D)
	@$(CC) $(INC) -c $< -o $@

simple:
	@clear
	@make all -s
	./$(NAME) input.txt
	@make fclean -s

all:	$(NAME)

clean:
	$(RM) $(OBJ)
	$(RM) $(OBJ_DIR)

fclean:	clean
	$(RM) $(NAME)

re:		fclean simple

.PHONY:	simple all clean fclean re