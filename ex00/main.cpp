/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkavalia <lkavalia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 16:32:17 by lkavalia          #+#    #+#             */
/*   Updated: 2023/05/16 15:29:05 by lkavalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
    {
    Bureaucrat  b1;
    Bureaucrat  b2;
    Bureaucrat  b3(b2);

    std::cout << YELL "\nBasic tests: ------------------" BLANK << std::endl;
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
        std::cout << "Grade: " << b1.getGrade() << std::endl;
        for (int i = b1.getGrade(); i <= 150; i++)
            b1.decrementGrade();
        std::cout << CYAN "B1 decrement:   " BLANK << b1;
        for (int i = b1.getGrade(); i >= 1; i--)
            b1.incrementGrade();
        std::cout << CYAN "B1 increment:   " BLANK << b1;
    }
    std::cout << YELL "\nExceptions: ------------------" BLANK << std::endl;
    {
        Bureaucrat  wrong_b("Jack", 0);

        std::cout << "Wrong_b: " << wrong_b << std::endl; 
        wrong_b.incrementGrade();
        wrong_b.decrementGrade();
        std::cout << "Wrong_b after decrement: " << wrong_b; 
        std::cout << YELL << "STILL works!" << BLANK << std::endl;
    }
    return (0);
}