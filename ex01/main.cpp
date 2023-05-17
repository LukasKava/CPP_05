/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkavalia <lkavalia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 16:32:17 by lkavalia          #+#    #+#             */
/*   Updated: 2023/05/17 20:52:28 by lkavalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

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
    std::cout << YELL "\nBasic tests forms: ------------------" BLANK << std::endl;

    Form    a1;

	try	{	Form	a2("Radio tax", 151, 0);}
	catch (Form::GradeTooHighException&	e)
	{
		std::cout << RED "Check the Form min_to_sign and min_to_execute they should be " << e.what() << BLANK << std::endl;
	}
	catch (Form::GradeTooLowException&	e)
	{
		std::cout << RED "Check the Form min_to_sign and min_to_execute they should be " << e.what() << BLANK << std::endl;
	}

	Form		a3("Radio tax legal version", 3, 3);
	Bureaucrat	test_b("Max", 5);

	try	{	a3.beSigned(test_b);}
	catch (Form::GradeTooLowException& e)
	{
		std::cerr << RED << "Ups form: " << a3.getName() << " cannot be signed by: " << test_b.getName() << '!' << BLANK << std::endl;
	}
	
	test_b.signForm(a3, "We neeed radio!!!!!!");
	std::cout << a1 << std::endl;
	std::cout << a3 << std::endl;
    return (0);
}