
# include <iostream>
# include "BitcoinExchange.hpp"


int main(int ac,char **av) {
    try {
        BitcoinExchange data(ac,av);
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
}