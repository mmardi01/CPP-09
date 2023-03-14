
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

void BitcoinExchange::insertData() {
    std::ifstream valuesFile(inputFile), data(dataFile);
    std::string line;
    char *date;
    char *value;
    if (!valuesFile)
        throw std::runtime_error("Error: could not open file.");
    if (!data)
        throw std::runtime_error("Error: you must have a data.csv file");
    getline(data, line);
    date = strtok((char*)line.c_str()," ,");
    value = strtok(NULL ," ,");
    if (!value || strcmp(date,"date") || strcmp(value,"exchange_rate"))
        throw std::runtime_error("Error: in data.csv file");
    while(getline(data, line)) {
        date = strtok((char*)line.c_str()," ,");
        value = strtok(NULL ," ,");
        if (!value)
            throw std::runtime_error("Error: in data.csv file");
        try {
            float v = std::stof(value);
            exchanges.insert(std::make_pair(date,v));
        }
        catch (...) {
            std::cout << "Error: in data.csv file\n";
            return;
        }
    }
    std::map<std::string,float>::iterator it = exchanges.begin();
    while (it != exchanges.end()) {
        std::cout << it->first << " " << it->second << std::endl;
        it++;
    }
}

BitcoinExchange::~BitcoinExchange() {};