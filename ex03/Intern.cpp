/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkavalia <lkavalia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 12:33:12 by lkavalia          #+#    #+#             */
/*   Updated: 2023/05/22 14:03:30 by lkavalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

//Canonical-form	----------------------------------------------------------->

Intern::Intern(void){	std::cout << "Default Intern constructor has been called!" << std::endl;}

Intern::Intern(const Intern& other){	*this = other;}

Intern::~Intern(void){	std::cout << RED "Default Intern destructor has been called!" BLANK << std::endl;}

Intern&	Intern::operator=(const Intern& other)
{
	(void)other;
	return (*this);
}

//Member functions	----------------------------------------------------------->

AForm	*Intern::makeForm(std::string form_name, std::string target) const
{
	std::string	possible_form_names[4] = {"Presidential pardon", "Robotomy request", "Shrubbery creation"};
	for (int i = 0; i < 3; i++)
	{
		if (possible_form_names[i].compare(form_name) == 0)
		{
			std::cout << GREEN "Intern creates " + form_name << BLANK << std::endl;
			switch (i)
			{
				case 0:
					return (new PresidentialPardonForm(target));
				case 1:
					return (new RobotomyRequestForm(target));
				case 2:
					return (new ShrubberyCreationForm(target));
			}
		}
	}
	return (NULL);
}