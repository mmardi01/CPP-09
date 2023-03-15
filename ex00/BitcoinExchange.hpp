


# ifndef _BITCOIN
# define _BITCOIN

# include <map>
# include <iostream>
# include "fstream"
# include <cstring>
class BitcoinExchange {
    private: 
        std::map<std::string,float, std::greater<std::string> > exchanges;
        std::string dataFile;
        std::string inputF;
    public:
        BitcoinExchange(int ac,char **av);
        BitcoinExchange(const BitcoinExchange &x);
        BitcoinExchange& operator = (const BitcoinExchange &x);
        ~BitcoinExchange();
    private:
        void insertData();
        void PrintResults();
        bool checkLine(std::string line,int t);
        bool checkDate(std::string date);
        bool checkYearMonthDay(std::string _year, std::string _month, std::string _day);
        bool checkValue(std::string val);
};


# endif