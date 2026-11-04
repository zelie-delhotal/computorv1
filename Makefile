# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gdelhota@student.42perpignan.fr            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/11/04 17:16:15 by gdelhota          #+#    #+#              #
#    Updated: 2026/11/04 20:35:19 by gdelhota         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = computor

CXX = c++

CPPFLAGS = -Wall -Wextra -Werror

SRC_DIR = srcs/

OBJ_DIR = objs/

INCLUDES = includes

SRCS = main.cpp computor.cpp

OBJS = $(SRCS:%.cpp=%.o)

OBJS:= $(addprefix $(OBJ_DIR), $(OBJS))

SRCS := $(addprefix $(SRC_DIR), $(SRCS))

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	mkdir -p $(@D)
	$(CXX) $(CPPFLAGS) -I$(INCLUDES) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CPPFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all
