/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkavalia <lkavalia@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:51:38 by lkavalia          #+#    #+#             */
/*   Updated: 2023/05/18 12:55:26 by lkavalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

//Constructor
AForm::AForm(void): _name("Default"), _form_signed(false), _min_grade_to_sign(10), _min_grade_to_execute(10)
{
    std::cout << GREEN "Default AForm constructor has been called!" BLANK << std::endl;
}

AForm::AForm(std::string name, int min_to_sign, int min_to_execute): _name(name), _form_signed(false), _min_grade_to_sign(min_to_sign), _min_grade_to_execute(min_to_execute)
{
    std::cout << GREEN << _name << " AForm constructor has been called!" BLANK << std::endl;
    if (min_to_sign < 1 || min_to_execute < 1)
		throw	GradeTooHighException();
	if (min_to_sign > 150 || min_to_execute > 150)
		throw	GradeTooLowException();
}

//Copy constructor
AForm::AForm(const AForm& other): _name(other._name), _form_signed(other._form_signed), _min_grade_to_sign(other._min_grade_to_sign), _min_grade_to_execute(other._min_grade_to_execute)
{
    std::cout << GREEN << "AForm Copy constructor has been called!" << std::endl;
}

AForm&	AForm::operator=(const AForm& other)
{
	this->_form_signed = other._form_signed;
	return (*this);
}

//Destructor
AForm::~AForm(void)
{
	std::cout << RED << "AForm destructor!" << BLANK << std::endl;
}

//Getters	-------------------------------------->
std::string	AForm::getName(void) const {	return (_name);}

bool	AForm::getForm(void) const {	return (_form_signed);}

int		AForm::getMinGradeToSign(void) const {	return (_min_grade_to_sign);}

int		AForm::getMinGradeToExecute(void) const { return (_min_grade_to_execute);}

//Member functions	------------------------------>
void	AForm::checkGrade(int& grade)
{
	if (grade < 1)
		throw	GradeTooHighException();
	if (grade > 150)
		throw	GradeTooLowException();
}

void	AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > _min_grade_to_sign)
		throw	GradeTooLowException();
	if (bureaucrat.getGrade() > _min_grade_to_execute)
		throw	GradeTooLowException();
	_form_signed = true;
}

void	AForm::copy_form_status(const bool form_status)
{
	this->_form_signed = form_status;
}

//Exeptions	---------------------------------------------->
const char	*AForm::GradeTooHighException::what() const throw()
{
	return	(" is too high.");
}

const char	*AForm::GradeTooLowException::what() const throw()
{
	return	(" is too low.");
}

//Stream Overload	--------------------------------------->
std::ostream&	operator<<(std::ostream& os, const AForm& form)
{
	os << "Name: " << form.getName() << " signed form: " << form.getForm() << " minimum grade to sign: " << form.getMinGradeToSign() << " minimum grade to execute: " << form.getMinGradeToExecute() << '.' << std::endl; 
	return (os);
}