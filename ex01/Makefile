# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmardi <mmardi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/17 14:48:25 by mmardi            #+#    #+#              #
#    Updated: 2023/03/17 15:46:50 by mmardi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = RPN

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

HEADER = RPN.hpp

SRC = RPN.cpp main.cpp

OBJ =  $(SRC:.cpp=.o)

all: $(NAME)
%.o: %.cpp 
	c++ $(CXXFLAGS) -o $@  -c $<

$(NAME): $(OBJ) $(HEADER)
	c++ $(CXXFLAGS) $(SRC) -o $(NAME)

clean:
	@rm -rf $(OBJ)
	
fclean: clean
	@rm -rf $(NAME)

re: fclean all