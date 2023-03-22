

# ifndef _PMERGEME_
# define _PMERGEME_

# include <iostream>
# include <vector>
# include <deque>
# include <stdlib.h>
#include <sys/time.h>
# include "fstream"

class PmergeMe {
    private:
        std::vector<int> vec;
        std::deque<int> deq;
    public:
        PmergeMe();
        PmergeMe(int ac, char **av);
        PmergeMe(const PmergeMe& x);
        PmergeMe& operator = (const PmergeMe& x);
        ~PmergeMe();
    private:
        bool checkArg(std::string arg);
        template<class T>
        void merge(T& arr, int l, int m, int r);
        template<class T>
        void dev_merge(T& arr, int l, int r);

};

# endif