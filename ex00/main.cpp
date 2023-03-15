
# include <iostream>
# include "BitcoinExchange.hpp"


int main(int ac,char **av) {
    try {
        BitcoinExchange data(ac,av);
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
//   std::string a = "2011-01-03";
//   std::cout << a.substr(0, 4) << std::endl;
//   std::cout << a.substr(5, 2) << std::endl;
//   std::cout << a.substr(8, 2) << std::endl;
}