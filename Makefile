# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmardi <mmardi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/14 15:46:15 by mmardi            #+#    #+#              #
#    Updated: 2023/03/14 15:56:29 by mmardi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = btc

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

HEADER = BitcoinExchange.hpp

SRC = BitcoinExchange.cpp main.cpp

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