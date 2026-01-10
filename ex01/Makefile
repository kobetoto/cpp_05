# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thodavid <thodavid@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/06 14:51:33 by thodavid          #+#    #+#              #
#    Updated: 2026/01/09 14:12:28 by thodavid         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#####
#Var#
#####
NAME		= Bureaucrat01
FLAGS		= -Wall -Wextra -Werror -std=c++98
SRCDIR		= src
OBJDIR		= obj
INCLUDES	= -I.

#####
#Src#
#####
SRC			= main Form Bureaucrat
SRCS		= $(addprefix $(SRCDIR)/,$(addsuffix .cpp,$(SRC)))
OBJ			= $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SRCS))

#######
#Rules#
#######
all: $(NAME)

$(NAME): $(OBJ)
		c++ $(FLAGS) $(OBJ) -o $(NAME)
		@echo "✅ ready ✅"

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
		@mkdir -p $(dir $@)
		c++ $(FLAGS) $(INCLUDES) -c $< -o $@

clean:
		rm -rf $(OBJDIR)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
