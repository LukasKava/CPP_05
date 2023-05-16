/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkavalia <lkavalia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 16:32:25 by lkavalia          #+#    #+#             */
/*   Updated: 2023/05/15 14:04:36 by lkavalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

//Constructor
Bureaucrat::Bureaucrat(void): _name("Peter"), _grade(3)
{
    std::cout << GREEN "Default constructor has been called!" BLANK << std::endl;
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
    std::cout << RED "Bureaucrat destructor was called!" BLANK << std::endl;
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
}

void    Bureaucrat::decrementGrade(void)
{
    _grade++;
}

std::ostream&   operator<<(std::ostream& os, const Bureaucrat& obj)
{
    os << obj.getName() << ", bureaucrat grade " << obj.getGrade() << '.' << std::endl;
    return (os); 
}

