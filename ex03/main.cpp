/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkavalia <lkavalia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 16:32:17 by lkavalia          #+#    #+#             */
/*   Updated: 2023/05/22 12:09:07 by lkavalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

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

    std::cout << YELL "\nExceptions Bureaucrats: ------------------" BLANK << std::endl;
    {
        Bureaucrat  wrong_b("Jack", 0);

        std::cout << "Wrong_b: " << wrong_b << std::endl; 
        wrong_b.incrementGrade();
        wrong_b.decrementGrade();
        std::cout << "Wrong_b after decrement: " << wrong_b; 
        std::cout << YELL << "STILL works!" << BLANK << std::endl;
    }
	
	std::cout << YELL "\nBasic tests for Presidential forms: ------------------" BLANK << std::endl;
	{
		Bureaucrat				b1("Marie", 2);
		PresidentialPardonForm	p1;
		PresidentialPardonForm	p2("PIKOBELLA");
		PresidentialPardonForm	p3(p2);
		
		std::cout << "Bureaucrat.	" << b1;
		p2.beSigned(b1);
		std::cout << "1.	" << p1 << YELL "target: " BLANK << p1.getTarget() << std::endl;
		std::cout << "2.	" << p2 << YELL "target: " BLANK << p2.getTarget() << std::endl;
		std::cout << "3.	" << p3 << YELL "target: " BLANK << p3.getTarget() << std::endl;
		p3 = p2;
		std::cout << "4.	" << p3 << YELL "target: " BLANK << p3.getTarget() << std::endl;
		b1.executeForm(p3);
        std::cout << std::endl;
	}
    
    std::cout << YELL "\nBasic tests for Robotomy Requests: ------------------" BLANK << std::endl;
	{
		Bureaucrat				b1("Robot", 10);
		RobotomyRequestForm	    p1;
		RobotomyRequestForm     p2("Maximus");
		RobotomyRequestForm     p3(p2);
		
		std::cout << "Bureaucrat.	" << b1;
		p1.beSigned(b1);
		std::cout << "1.	" << p1 << YELL "target: " BLANK << p1.getTarget() << std::endl;
		std::cout << "2.	" << p2 << YELL "target: " BLANK << p2.getTarget() << std::endl;
		std::cout << "3.	" << p3 << YELL "target: " BLANK << p3.getTarget() << std::endl;
		p3 = p2;
		std::cout << "4.	" << p3 << YELL "target: " BLANK << p3.getTarget() << std::endl;
		b1.executeForm(p3);
        std::cout << std::endl;
	}
    
    std::cout << YELL "\nBasic tests for Shrubbery Creations: ------------------" BLANK << std::endl;
	{
		Bureaucrat					b1("Blueberry", 10);
		ShrubberyCreationForm		p1;
		ShrubberyCreationForm		p2("JerryBerry");
	    ShrubberyCreationForm		p3(p2);
		
		std::cout << "Bureaucrat.	" << b1;
		p1.beSigned(b1);
		std::cout << "1.	" << p1 << YELL "target: " BLANK << p1.getTarget() << std::endl;
		std::cout << "2.	" << p2 << YELL "target: " BLANK << p2.getTarget() << std::endl;
		std::cout << "3.	" << p3 << YELL "target: " BLANK << p3.getTarget() << std::endl;
		p3 = p2;
		std::cout << "4.	" << p3 << YELL "target: " BLANK << p3.getTarget() << std::endl;
		b1.executeForm(p3);
		b1.executeForm(p1);
        std::cout << std::endl;
	}
	
    return (0);
}