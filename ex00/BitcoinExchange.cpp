
# include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(int ac, char **av) : dataFile("./data.csv") {
    switch (ac){
        case 2:
            inputF = av[1];
            break;
        default:
            throw std::runtime_error("Error: could not open file.");
    }
    insertData();
    PrintResults();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &x)  {
    exchanges = x.exchanges;
    dataFile  = x.dataFile;
    inputF = x.inputF;
}
BitcoinExchange& BitcoinExchange::operator = (const BitcoinExchange &x) {
    exchanges = x.exchanges;
    dataFile = x.dataFile;
    inputF = x.inputF;
    return *this;
}

void BitcoinExchange::insertData() {
    std::ifstream  data(dataFile.c_str());
    std::string line;
    char *date;
    char *value;
    if (!data)
        throw std::runtime_error("Error: you must have a data.csv file");
    getline(data, line);
    while(getline(data, line)) {
        date = strtok((char*)line.c_str()," ,");
        value = strtok(NULL ," ,");
        float v = std::atof(value);
        exchanges.insert(std::make_pair(date,v));
    }
    // std::map<std::string,float>::iterator it = exchanges.begin();
    // while (it != exchanges.end())
    // {
    //     std::cout << it->first << "| |" << it->second << std::endl; 
    //     it++;
    // } 
}


bool BitcoinExchange::checkYearMonthDay(std::string _year, std::string _month, std::string _day) {
    int year = atoi(_year.c_str());
    int month = atoi(_month.c_str());
    int day = atoi(_day.c_str());
    if (year < 2009 || year > 2023)
        return true;
    if (month > 12 || month < 1)
        return true;
    if (day > 31 || day < 1)
        return true;
    return false;
}

bool BitcoinExchange::checkDate(std::string line) {

    if (line.size() != 10)
        return true;
    for (size_t i = 0; i < 10 ; i++) {
        if (i < 4 && !isdigit(line[i]))
            return true;
        else if ((i == 4 ||i == 7) && line[i] != '-')
            return true;
        else if ((i == 5 || i == 6 || i == 8 || i == 9) && !isdigit(line[i]))
            return true; 
    }
    if (checkYearMonthDay(line.substr(0, 4), line.substr(5, 2), line.substr(8, 2)))
        return true;
    return false;
}

bool BitcoinExchange::checkValue(std::string val) {
    int k = 0;
    for (size_t i = 0; i < val.size(); i++)
    {
        if (i == 0 && (val[i] == '-' || val[i] == '+'));
        else if (!isdigit(val[i]) && val[i] != '.')
            return true;
        if (val[i] == '.')
            k++;
        if (k > 1)
            return true;
    }
    return false;
}

bool BitcoinExchange::checkLine(std::string line, int t) {
    char *first;
    char *second;
    if (t == 0) {
        first = strtok((char *)line.c_str(), "|");
        second = strtok(NULL, "|");
        if (!second)
            return true;
    }
    else if (t == 1) {
        int k = 0;
        for (size_t i = 0; i < line.size(); i++)
        {
            if (!isdigit(line[i]) && line[i] != '-' && line[i] != '|' && line[i] != ' ' && line[i] != '.')
                return true;
            if (line[i] == '|') 
                k++;
            if (k > 1) 
                return true;
        }  
    }
    return false;
}

void BitcoinExchange::PrintResults() {

    std::ifstream inputFile(inputF.c_str());
    std::string line;
    if (!inputFile)
        throw std::runtime_error("Error: could not open file.");
    getline(inputFile,line);
    if (checkLine(line,0)) // 0 to check the first line
        throw std::runtime_error("Error:  first line syntax \"key | value\"");
    while(getline(inputFile,line)) {
         if (checkLine(line, 1))  // 1 for date & value
            std::cout << "Error: bad input => "  << line << std::endl;
        else {
            char *first = strtok((char *)line.c_str(), " |");
            char *second = strtok(NULL, " |");
            if (!first || checkDate(first) || !second)
                std::cout << "Error: bad input => "  << line << std::endl;
            else if (checkValue(second))
                std::cout << "Error: bad input => "  << line << std::endl;
            else {
                if (atof(second) < 0)
                    std::cout << "Error: not a positive number." << std::endl;
                else if (atof(second) > 1000)
                    std::cout << "Error: too large a number." << std::endl;
                else {
                    std::cout << first << " => " << second << " = " << exchanges.lower_bound(first)->second *  atof(second) << std::endl;;
                }

            }
        }
    }
    
}

BitcoinExchange::~BitcoinExchange() {};