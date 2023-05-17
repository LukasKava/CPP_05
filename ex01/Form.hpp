/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkavalia <lkavalia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:51:43 by lkavalia          #+#    #+#             */
/*   Updated: 2023/05/17 18:56:33 by lkavalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>
#include <exception>
#include <string>

class	Bureaucrat;

class   Form
{
    private:
        const std::string   _name;
        bool                _form_signed;
        const int           _min_grade_to_sign;
        const int           _min_grade_to_execute;
    public:

        //Canonical form	--------------------------->
		Form(void);
		Form(std::string name, int min_grade_to_sign, int min_grade_to_execute);
		Form(const Form& other);
		~Form(void);
		
		Form&	operator=(const Form& other);
		
		//Getters	----------------------------------->
		std::string	getName(void) const;
		bool		getForm(void) const;
		int			getMinGradeToSign(void) const;
		int			getMinGradeToExecute(void) const;

        //Exception classes --------------------------->
        class   GradeTooHighException: public std::exception
        {
            public:
                virtual const char  *what() const throw();
        };
        
        class   GradeTooLowException: public std::exception
        {
            public:
                virtual const char  *what() const throw();
        };
        
		//Member functions	--------------------------->
		void	beSigned(const Bureaucrat& bureaucrat);
		void	checkGrade(int& grade);
};

std::ostream&	operator<<(std::ostream& os, const Form& form);

#endif