/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkavalia <lkavalia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 16:32:17 by lkavalia          #+#    #+#             */
/*   Updated: 2023/05/15 14:06:59 by lkavalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
    Bureaucrat  b1;
    Bureaucrat  b2;
    Bureaucrat  b3(b2);

    std::cout << YELL "Basic tests: ------------------" BLANK << std::endl;
    std::cout << "B1 before: " << b1;
    b1.decrementGrade();
    std::cout << "B1 after:  " << b1;
    std::cout << "B2:        " << b2;
    std::cout << "B3:        " << b3;
    b2.incrementGrade();
    std::cout << "B2 inc:    " << b2;
    std::cout << "B3 dec:    " << b3;
    b1 = b2;
    std::cout << "B1 over:   " << b1;

    std::cout << YELL "Exceptions: ------------------" BLANK << std::endl;
    
    return (0);
}