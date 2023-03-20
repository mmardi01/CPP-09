

# ifndef _PMERGEME_
# define _PMERGEME_

# include <iostream>
# include <vector>
# include <deque>
# include <stdlib.h>
#include <sys/time.h>


class PmergeMe {
    private:
        std::vector<int> vec;
        std::deque<int> deq;
    public:
        PmergeMe(int ac,char **av);
        ~PmergeMe();
    private:
        bool checkArg(std::string arg);
        template<class T>
        void merge(T& arr, int l, int m, int r);
        template<class T>
        void dev_merge(T& arr, int l, int r);

};

# endif