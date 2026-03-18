# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brturcio <brturcio@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/07 13:12:10 by brturcio          #+#    #+#              #
#    Updated: 2026/03/18 18:00:20 by brturcio         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= btc
CC			:= c++
CFLAGS		:= -Wall -Wextra -Werror -std=c++98 -g

DIR_SRSC	:= sources/
DIR_OBJS	:= objects/

SOURCES		:= main.cpp BitcoinExchange.cpp
OBJECTS		:= $(addprefix $(DIR_OBJS), $(SOURCES:.cpp=.o))

INCLUDES	:= -Iincludes

GREEN		:= \033[0;32m
RESET		:= \033[0m

all: $(NAME)

$(DIR_OBJS)%.o: $(DIR_SRSC)%.cpp
	@mkdir -p $(DIR_OBJS)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJECTS)
	@$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)
	@echo "$(GREEN)✔ $(NAME) Created Successfully!$(RESET)"

clean: 
	@rm -rf $(DIR_OBJS)
	@echo "$(GREEN)✔ Objects Cleaned$(RESET)"

fclean: clean
	@rm -rf $(NAME)
	@echo "$(GREEN)✔ Excecutable Cleaned$(RESET)"

re: fclean all

.PHONY: all clean fclean re
