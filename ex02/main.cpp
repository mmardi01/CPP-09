# include "PmergeMe.hpp"

int  main(int ac, char **av) {
    
    try {
        PmergeMe o(ac,av);
    }
    catch(const std::exception& e)  {
        std::cerr << e.what() << '\n';
    }
}