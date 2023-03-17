/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmardi <mmardi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:10:20 by mmardi            #+#    #+#             */
/*   Updated: 2023/03/17 16:13:19 by mmardi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef _RPN_
# define _RPN_

# include <iostream>
# include <stack>

class RPN {
    private:
        std::stack<std::string> arguments;
        std::stack<int> values;    
    public:
        RPN();
        RPN(int ac, char **av);
        RPN(const RPN& x);
        RPN& operator = (const RPN& x);
        ~RPN();
    private:
        void insertArguments(std::string arg);
        bool checkArguments(std::string arg);
};

# endif