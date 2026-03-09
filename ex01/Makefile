# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erpascua <erpascua@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/21 15:23:43 by erpascua          #+#    #+#              #
#    Updated: 2026/03/09 17:12:02 by erpascua         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.NOTPARALLEL:re clean fclean
.SILENT:

################################################################################
#										   									   #
#									VARIABLES								   #
#										   									   #
################################################################################

NAME =	RPN

SRCS =	srcs/main.cpp \
		srcs/RPN.cpp \

OBJ_DIR = obj
OBJ = $(SRCS:%.cpp=$(OBJ_DIR)/%.o)

CC = c++
CFLAGS = -Wall -Wextra -Werror -I./includes -std=c++98 -g -pedantic

################################################################################
#										   									   #
#									  RULES   								   #
#										  									   #
################################################################################


all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	@$(CC) $(OBJ) $(CFLAGS) -o $(NAME)
	@echo "✅  $@ compiled !"

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)
	@echo "✅  Object files removed"

fclean: clean
	@rm -f $(NAME)
	@echo "✅  Executable and libraries removed"

re: fclean 
	make all

.PHONY: all clean fclean re
