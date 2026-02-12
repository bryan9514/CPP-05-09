# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brturcio <brturcio@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/11 18:33:14 by brturcio          #+#    #+#              #
#    Updated: 2026/02/12 13:10:27 by brturcio         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= scalarconverter
CC			:= c++
CFLAGS		:= -Wall -Wextra -Werror -std=c++98

DIR_SRCS	:= sources/
DIR_OBJS	:= objs/

SOURCES		:= main.cpp ScalarConverter.cpp
OBJECTS		:= $(addprefix $(DIR_OBJS), $(SOURCES:.cpp=.o))

INCLUDES	:= -Iincludes

GREEN		:= \033[0;32m
RESET		:= \033[0m

all: $(NAME)

$(DIR_OBJS)%.o : $(DIR_SRCS)%.cpp
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
	@echo "$(GREEN)✔ Executable Cleaned$(RESET)"

re: fclean all

.PHONY: all clean fclean re


