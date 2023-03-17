/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmardi <mmardi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:10:18 by mmardi            #+#    #+#             */
/*   Updated: 2023/03/17 19:26:16 by mmardi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "RPN.hpp"

RPN::RPN() {};

bool RPN::checkArguments(std::string arg) {
    if (arg.size() == 0)
        return true;
    for (size_t i = 0; i < arg.size(); i++)
    {
        if(!isdigit(arg[i]) && arg[i] != '*' &&  arg[i] != '+'  &&  arg[i] != '-' &&  arg[i] != '/' && arg[i] != ' ')
            return true;
    }
    
    return false;   
}

void RPN::insertArguments(std::string arg) {
 
    char *s = strtok((char *)arg.c_str(), " ");
    std::stack<std::string> tmp;
    while(s) {
        tmp.push(s);
        s = strtok(NULL, " ");
    }

    while(tmp.size() > 0) {
        if (tmp.top().size() > 1)
            throw std::runtime_error("ERROR: bad input.");
        arguments.push(tmp.top());
        tmp.pop();
    }
     while(arguments.size() > 0) {
        std::cout << arguments.top() << std::endl;
        arguments.pop();
    }
}

RPN::RPN(int ac, char **av) {
    if (ac != 2)
        throw std::runtime_error("ERROR: too few or too many arguemnts.");
    if (checkArguments(av[1]))
        throw std::runtime_error("ERROR: bad input.");
    insertArguments(av[1]);
}

RPN::~RPN(){};