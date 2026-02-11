# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brturcio <brturcio@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/11 18:33:14 by brturcio          #+#    #+#              #
#    Updated: 2026/02/11 19:25:59 by brturcio         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= scalarconvert
CC			:= c++
CFLAGS		:= -Wall -Wextra -Werror -std=c++98

DIR_SRCS	:= sources/
DIR_OBJS	:= objs/

SOURCES		:= main.cpp scalarconvert.cpp
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


clean:

fclean:

re:

.PHONY: all clean fclean re


