/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkavalia <lkavalia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 22:48:05 by lkavalia          #+#    #+#             */
/*   Updated: 2023/05/21 23:10:50 by lkavalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

//Canonical for	--------------------------------------------------------------->
RobotomyRequestForm::RobotomyRequestForm(void): AForm("Robotomy request", 72, 45), _target("Bob")
{
	std::cout << GREEN "ROBOTOMY REQUEST" BLANK << " default constructor has been called!" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("Robotomy request", 72, 45), _target(target)
{
	std::cout << GREEN "ROBOTOMY REQUEST" BLANK << " constructor has been called!" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other): AForm(other.getName(), other.getMinGradeToSign(), other.getMinGradeToExecute())
{
	std::cout << GREEN "ROBOTOMY REQUEST" BLANK << " copy constructor has been called!" << std::endl;
	*this = other;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << RED "ROBOTOMY REQUEST" BLANK << " destructor has been called!" << std::endl;
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	std::cout << GREEN "ROBOTOMY REQUEST" BLANK << " equal assignment operator overload has been called!" << std::endl;
	this->copy_form_status(other.getForm());
	_target = other._target;
	return	(*this);
}

//Getters	------------------------------------------------------------->
std::string	RobotomyRequestForm::getTarget(void) const
{
	return (_target);
}

//Member functions	------------------------------------------------------>
bool	RobotomyRequestForm::execute(Bureaucrat const & executor)const
{
	if (this->checkExecRequirements(executor) == false)
		return (false);
    srand (time(NULL));
    std::cout << CYAN "............  Drillinggggg noises ......................" BLANK << std::endl;
    if (rand() % 2 == 0)
    {
        std::cout << RED << "Robotomy on " << _target << " has failed!" << BLANK << std::endl;
        return (false);
    }
	std::cout << _target << " has been robotomised!" << std::endl;
	return (true);
}