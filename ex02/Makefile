NAME = PmergeMe

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

HEADER = PmergeMe.hpp

SRC = PmergeMe.cpp main.cpp

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