
# include "PmergeMe.hpp"

PmergeMe::PmergeMe() {};

PmergeMe::PmergeMe(const PmergeMe &x) : vec(x.vec), deq(x.deq){
}

PmergeMe& PmergeMe::operator = (const PmergeMe &x) {
    vec = x.vec;
    deq = x.deq;
    return *this;
}

bool PmergeMe::checkArg(std::string arg) {
    for (size_t i = 0; i < arg.length(); i++) {
        if (!isdigit(arg[i]))
            return true;
    }
    return false;
}

template<class T>
void PmergeMe::merge(T& arr, int l, int m, int r) {
    T tmp1,tmp2;
    for (int i = l; i <= m; i++)
        tmp1.push_back(arr[i]);
    for (int i = m + 1; i <= r; i++)
        tmp2.push_back(arr[i]);
    size_t k , j, i;
    j = 0;
    k = 0;
    i = l;   
    while (j < tmp1.size() && k < tmp2.size())
    {
        if (tmp1[j] <= tmp2[k]) 
            arr[i++] = tmp1[j++];
        else
            arr[i++] = tmp2[k++];
    }
    while (j < tmp1.size())
            arr[i++] = tmp1[j++];
     while (k < tmp2.size())
            arr[i++] = tmp2[k++];
}

template<class T>
void PmergeMe::dev_merge(T& arr, int l,int r) {
    int m;
    if (l < r) {
         m = l + (r - l) / 2;
        dev_merge(arr, l, m);
        dev_merge(arr, m+1, r);
        merge(arr, l,m,r);
    }
}

PmergeMe::PmergeMe(int ac,char **av) {
    timeval start;
    timeval end;
    float t_spent,t_spent2;
    if (ac <= 2)
        throw std::runtime_error("ERROR: Too few arguments.");
    int i = 1;
    while (av[i])
    {
        if (checkArg(av[i])) 
            throw std::runtime_error("ERROR: Bad input.");
        if (2147483647 < atol(av[i]))
            throw std::runtime_error("ERROR: Too large number.");
        vec.push_back(atoi(av[i]));
        deq.push_back(atoi(av[i]));
        i++;
    }
    std::cout << "Before: ";
    for (size_t i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
    gettimeofday(&start,NULL);
    dev_merge(vec,0,vec.size()-1);
    gettimeofday(&end,NULL);
    t_spent = ((end.tv_sec * 1000000) + end.tv_usec) - ((start.tv_sec * 1000000) + start.tv_usec);
    gettimeofday(&start,NULL);
    dev_merge(deq,0,deq.size()-1);
    gettimeofday(&end,NULL);
    t_spent2 = ((end.tv_sec * 1000000) + end.tv_usec) - ((start.tv_sec * 1000000) + start.tv_usec);
    std::cout << "After: ";
    for (size_t i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "Time to process a range of " << vec.size() << " elements with std::vector  : " << t_spent << " us\n";
    std::cout << "Time to process a range of " << vec.size() << " elements with std::deque  : " << t_spent2 << " us\n";
}

PmergeMe::~PmergeMe() {

}