/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkavalia <lkavalia@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:51:43 by lkavalia          #+#    #+#             */
/*   Updated: 2023/05/18 14:48:10 by lkavalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>
#include <exception>
#include <string>

class	Bureaucrat;
class	PresidentialPardonForm;

class   AForm
{
    private:
        const std::string   _name;
        bool                _form_signed;
        const int           _min_grade_to_sign;
        const int           _min_grade_to_execute;
    public:

        //Canonical form	--------------------------->
		AForm(void);
		AForm(std::string name, int min_grade_to_sign, int min_grade_to_execute);
		AForm(const AForm& other);
		~AForm(void);
		
		AForm&	operator=(const AForm& other);
		
		//Getters	----------------------------------->
		std::string	getName(void) const;
		bool		getForm(void) const;
		int			getMinGradeToSign(void) const;
		int			getMinGradeToExecute(void) const;
        
		//Member functions	--------------------------->
		void	checkGrade(int& grade);
		void	beSigned(const Bureaucrat& bureaucrat);
		void	copy_form_status(const bool form_status);

		//Pure virtual function
		virtual void	execute(Bureaucrat const & executor) const = 0;

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
};

std::ostream&	operator<<(std::ostream& os, const AForm& form);

#endif