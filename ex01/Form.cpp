/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkavalia <lkavalia@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:51:38 by lkavalia          #+#    #+#             */
/*   Updated: 2023/05/18 10:44:37 by lkavalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

//Constructor
Form::Form(void): _name("Default"), _form_signed(false), _min_grade_to_sign(10), _min_grade_to_execute(10)
{
    std::cout << GREEN "Default constructor has been called!" BLANK << std::endl;
}

Form::Form(std::string name, int min_to_sign, int min_to_execute): _name(name), _form_signed(false), _min_grade_to_sign(min_to_sign), _min_grade_to_execute(min_to_execute)
{
    std::cout << GREEN << _name << " constructor has been called!" BLANK << std::endl;
    if (min_to_sign < 1 || min_to_execute < 1)
		throw	GradeTooHighException();
	if (min_to_sign > 150 || min_to_execute > 150)
		throw	GradeTooLowException();
}

//Copy constructor
Form::Form(const Form& other): _name(other._name), _form_signed(other._form_signed), _min_grade_to_sign(other._min_grade_to_sign), _min_grade_to_execute(other._min_grade_to_execute)
{
    std::cout << GREEN << "Copy constructor has been called!" << std::endl;
}

Form&	Form::operator=(const Form& other)
{
	this->_form_signed = other._form_signed;
	return (*this);
}

//Destructor
Form::~Form(void)
{
	std::cout << RED << "Form destructor!" << BLANK << std::endl;
}

//Getters	-------------------------------------->
std::string	Form::getName(void) const {	return (_name);}

bool	Form::getForm(void) const {	return (_form_signed);}

int		Form::getMinGradeToSign(void) const {	return (_min_grade_to_sign);}

int		Form::getMinGradeToExecute(void) const { return (_min_grade_to_execute);}

//Member functions	------------------------------>
void	Form::checkGrade(int& grade)
{
	if (grade < 1)
		throw	GradeTooHighException();
	if (grade > 150)
		throw	GradeTooLowException();
}

void	Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > _min_grade_to_sign)
		throw	GradeTooLowException();
	if (bureaucrat.getGrade() > _min_grade_to_execute)
		throw	GradeTooLowException();
	_form_signed = true;
}

//Exeptions	---------------------------------------------->
const char	*Form::GradeTooHighException::what() const throw()
{
	return	(" is too high.");
}

const char	*Form::GradeTooLowException::what() const throw()
{
	return	(" is too low.");
}

//Stream Overload	--------------------------------------->
std::ostream&	operator<<(std::ostream& os, const Form& form)
{
	os << "Name: " << form.getName() << " signed form: " << form.getForm() << " minimum grade to sign: " << form.getMinGradeToSign() << " minimum grade to execute: " << form.getMinGradeToExecute() << '.' << std::endl; 
	return (os);
}