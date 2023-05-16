# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lkavalia <lkavalia@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/14 16:39:17 by lkavalia          #+#    #+#              #
#    Updated: 2023/05/14 16:44:44 by lkavalia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Bureaucrat

CC = c++

CPP_FLAGS = -Wall -Werror -Wextra -std=c++98 -fsanitize=address

SRC = main.cpp \
		Bureaucrat.cpp

all: $(NAME)

$(NAME): $(SRC)
		$(CC) $(CPP_FLAGS) $(SRC) -o $(NAME)

fclean:
	rm -f $(NAME)
	@echo "force cleaning!"

re: fclean all
	@echo "remaking files!"