


# ifndef _BITCOIN
# define _BITCOIN

# include <map>
# include <iostream>
# include "fstream"
# include <cstring>
class BitcoinExchange {
    private: 
        // std::map<std::string,int> values;
        std::map<std::string,float> exchanges;
        std::string dataFile;
        std::string inputFile;
    public:
        BitcoinExchange(int ac,char **av);
        BitcoinExchange(const BitcoinExchange &x);
        BitcoinExchange& operator = (const BitcoinExchange &x);
        ~BitcoinExchange();
    private:
        void insertData();
};


# endif