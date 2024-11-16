# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akoskine <akoskine@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/10 17:15:18 by akoskine          #+#    #+#              #
#    Updated: 2024/07/10 18:13:37 by akoskine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	span

CC			=	c++
CFLAGS		=	-Werror -Wextra -Wall -std=c++2a

INC_PATH	=	./includes/
INC			=	-I $(INC_PATH)

SRC_PATH	=	./sources/
SRC			=	main.cpp \
				Span.cpp

SRCS		=	$(addprefix $(SRC_PATH), $(SRC))

OBJ_PATH	=	./objects/
OBJ			=	$(SRC:.cpp=.o)
OBJS		=	$(addprefix $(OBJ_PATH), $(OBJ))

all: $(OBJ_PATH) $(NAME)

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)

$(OBJ_PATH)%.o: $(SRC_PATH)%.cpp
	$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@ $(INC)

clean:
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re