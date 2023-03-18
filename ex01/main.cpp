/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmardi <mmardi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:08:17 by mmardi            #+#    #+#             */
/*   Updated: 2023/03/18 00:24:57 by mmardi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include "RPN.hpp"
# include <iostream>

int main(int ac,char **av) {

    try {
        RPN o(ac,av);
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    } 
}