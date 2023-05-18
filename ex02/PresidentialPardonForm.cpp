/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkavalia <lkavalia@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 11:47:55 by lkavalia          #+#    #+#             */
/*   Updated: 2023/05/18 15:13:31 by lkavalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

//Canonical for	--------------------------------------------------------------->
PresidentialPardonForm::PresidentialPardonForm(void): AForm("Presidential Pardon", 25, 5), _target("MARK")
{
	std::cout << GREEN "PRESIDENTIAL PARDON" BLANK << " default constructor has been called!" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("Presidential Pardon", 25, 5), _target(target)
{
	std::cout << GREEN "PRESIDENTIAL PARDON" BLANK << " constructor has been called!" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other): AForm(other.getName(), other.getMinGradeToSign(), other.getMinGradeToExecute())
{
	std::cout << GREEN "PRESIDENTIAL PARDON" BLANK << " copy constructor has been called!" << std::endl;
	*this = other;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cout << RED "PRESIDENTIAL PARDON" BLANK << " destructor has been called!" << std::endl;
}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	std::cout << GREEN "PRESIDENTIAL PARDON" BLANK << " equal assignment operator overload has been called!" << std::endl;
	this->copy_form_status(other.getForm());
	_target = other._target;
	return	(*this);
}

//Getters	------------------------------------------------------------->
std::string	PresidentialPardonForm::getTarget(void) const
{
	return (_target);
}

//Member functions	------------------------------------------------------>
void	PresidentialPardonForm::execute(Bureaucrat const & executor)const
{
	(void) executor;
	std::cout << this->getTarget() << " as been pardoned by Zaphod Beeblebrox" << std::endl;
}