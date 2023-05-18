/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkavalia <lkavalia@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 16:32:25 by lkavalia          #+#    #+#             */
/*   Updated: 2023/05/18 13:42:29 by lkavalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

//Constructor
Bureaucrat::Bureaucrat(void): _name("Peter"), _grade(3)
{
    //std::cout << GREEN "Default constructor has been called!" BLANK << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name), _grade(grade)
{
    try	{checkGrade(grade);}
	catch (GradeTooHighException& exception)
	{
		_grade = 1;
		std::cerr << RED << exception.what() << BLANK << std::endl;
	}
	catch (GradeTooLowException& exception)
	{
		_grade = 1;
		std::cerr << RED << exception.what() << BLANK << std::endl;
	}
}

//Copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat& other): _name(other._name)
{
    std::cout << GREEN "Bureaucrat copy constructor!" BLANK << std::endl;
    *this = other;
}

//Destructor
Bureaucrat::~Bureaucrat(void)
{
    //std::cout << RED << getName() << " Bureaucrat destructor was called!" BLANK << std::endl;
}

//Copy assignment operator overload
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    std::cout << GREEN "Bureaucrat copy assigment overload!" BLANK << std::endl;
    this->_grade = other.getGrade();
    return (*this);
}

//Getters ------------------------------>
std::string Bureaucrat::getName(void) const  { return (_name);}

int Bureaucrat::getGrade(void) const    { return (_grade);}

//Member functions  -------------------->
void    Bureaucrat::incrementGrade(void)
{
    _grade--;
	try	{checkGrade(_grade);}
	catch (GradeTooHighException& exception)
	{
		_grade++;
		std::cerr << RED << exception.what() << BLANK << std::endl;
	}
}

void    Bureaucrat::decrementGrade(void)
{
    _grade++;
	try	{checkGrade(_grade);}
	catch (GradeTooLowException& exception)
	{
		_grade--;
		std::cerr << RED << exception.what() << BLANK << std::endl;
	}
}

void	Bureaucrat::checkGrade(int& grade)	const
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

void	Bureaucrat::signForm(AForm& form, const std::string reason) const
{
	if (form.getForm() == true)
	{
		std::cout << YELL "AForm was already signed by someone else!" BLANK << std::endl;
	}
	try {	form.beSigned(*this);}
	catch (AForm::GradeTooLowException& e)
	{
		std::cout << RED << this->getName() << " couldn't sign " << form.getName();
		std::cout << " because " + reason << BLANK << std::endl;
		return ; 
	}
	std::cout << GREEN << this->getName() << " signed " + form.getName() << BLANK << std::endl;
}

//Exceptions	------------------------------------->
const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high! It should be 1 or more!");
}

const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low! It should be 150 or less!");
}

std::ostream&   operator<<(std::ostream& os, const Bureaucrat& obj)
{
    os << obj.getName() << ", bureaucrat grade " << obj.getGrade() << '.' << std::endl;
    return (os); 
}

