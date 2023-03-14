
# include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(int ac, char **av) : dataFile("./data.csv") {
    switch (ac){
        case 2:
            inputFile = av[1];
            break;
        default:
            throw std::runtime_error("Error: could not open file.");
    }
    insertData();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &x)  {
    exchanges = x.exchanges;
    dataFile  = x.dataFile;
    inputFile = x.inputFile;
}
BitcoinExchange& BitcoinExchange::operator = (const BitcoinExchange &x) {
    exchanges = x.exchanges;
    dataFile = x.dataFile;
    inputFile = x.inputFile;
    return *this;
}

void BitcoinExchange::insertData() {
    std::ifstream valuesFile(inputFile.c_str()), data(dataFile.c_str());
    std::string line;
    char *date;
    char *value;
    if (!valuesFile)
        throw std::runtime_error("Error: could not open file.");
    if (!data)
        throw std::runtime_error("Error: you must have a data.csv file");
    getline(data, line);
    date = std::strtok((char*)line.c_str()," ,");
    value = strtok(NULL ," ,");
    if (!value || strcmp(date,"date") || strcmp(value,"exchange_rate"))
        throw std::runtime_error("Error: in data.csv file");
    while(getline(data, line)) {
        date = strtok((char*)line.c_str()," ,");
        value = strtok(NULL ," ,");
        if (!value)
            throw std::runtime_error("Error: in data.csv file");
        try {
            double v = std::stod(value);
            exchanges.insert(std::make_pair(date,v));
        }
        catch (...) {
            std::cout << "Error: in data.csv file\n";
            return;
        }
    }
    getline(valuesFile, line);
    date = strtok((char *)line.c_str(), " |");
    value = strtok(NULL, " |");
    if (!value || strcmp(date, "date") || strcmp(value, "value"))
        throw std::runtime_error("Error: in input file");
    while (getline(valuesFile, line))
    {
        date = strtok((char *)line.c_str(), " |");
        value = strtok(NULL, " |");
        if (!value)
            std::cout << "Error: bad input => " << date << "\n";
        else  if (exchanges.count(date) == 0)
            std::cout << "Error: date not found => " << date << "\n";
        else {
            double v;
            try
            {
                v = std::stod(value);
                exchanges.insert(std::make_pair(date, v));
            }
            catch (...) {
                std::cout << "Error: value is not a number => " << value << "\n";
            }
            if (v < 0)
                std::cout << "Error: not a positive number.\n";
            else if (v > 1000)
                std::cout << "Error: too large a number.\n";
            else
                std::cout << date << " => " << value << " = " << v * exchanges[date] << "\n";
        }
    }
}

BitcoinExchange::~BitcoinExchange() {};