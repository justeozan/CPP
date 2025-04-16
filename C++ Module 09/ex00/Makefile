.DEFAULT_GOAL = all

RESET = \e[0m
DISCRET = \e[90;3;3m

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
	@echo "$(DISCRET)./$(NAME) input.txt$(RESET)" && ./$(NAME) input.txt
	@chmod 000 input.txt
	@echo "$(DISCRET)chmod 000 input.txt\n./$(NAME) input.txt$(RESET)" && ./$(NAME) input.txt
	@chmod 777 input.txt
	@echo "$(DISCRET)./$(NAME) $(RESET)" && ./$(NAME) 
	@echo "$(DISCRET)./$(NAME) invalid_header.txt$(RESET)" && ./$(NAME) invalid_header.txt
	@echo "$(DISCRET)./$(NAME) non-exist.txt$(RESET)" && ./$(NAME) non-exist.txt
	@make fclean -s

all:	$(NAME)

clean:
	$(RM) $(OBJ)
	$(RM) $(OBJ_DIR)

fclean:	clean
	$(RM) $(NAME)

re:		fclean all

.PHONY:	simple all clean fclean re