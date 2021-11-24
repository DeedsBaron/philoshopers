# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbaron <dbaron@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/29 15:52:28 by dbaron            #+#    #+#              #
#    Updated: 2021/06/08 15:15:24 by dbaron           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
#-Wall -Wextra -Werror
FLAGS =  -MMD -Wall -Wextra -Werror

DIR_S = ./src

DIR_O = ./obj

CC = gcc
SOURCES = main.c ft_atoi.c ft_putnbr.c thug_life.c time.c routine.c parse.c\
		error.c display_message.c

SRCS = $(addprefix $(DIR_S)/,${SOURCES})

OBJS = $(addprefix $(DIR_O)/,${SOURCES:.c=.o})

all: dir $(NAME)

dir: 
	@echo "\033[0;32m"
	mkdir -p obj

$(DIR_O)/%.o: $(DIR_S)/%.c
	$(CC) $(FLAGS) -c $< -o $@ -g

$(NAME): $(OBJS)
	@echo "\033[0;35m"
	$(CC) $(FLAGS) $^ -o $@
	chmod 777 $(NAME)

norm:
	@echo "\033[0;32mnorminette $(DIR_S)/*.c\033[0m"
	@norminette $(DIR_S)/*.c
	@echo "\033[0;32mnorminette includes/*.h\033[0m"
	@norminette includes/*.h

clean:
	@echo "\033[0;33m"
	rm -rf $(DIR_O)

fclean: clean
	@echo "\033[0;33m"
	rm -f $(NAME)

re: fclean all

1:
	./philo 1 800 200 200
2:
	./philo 5 800 200 200
3:
	./philo 5 800 200 200 7
4:
	./philo 4 410 200 200
5:
	./philo 4 310 200 100

.PHONY: all lib clean fclean re

-include $(OBJS:.o=.d)