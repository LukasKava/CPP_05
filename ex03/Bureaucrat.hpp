/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkavalia <lkavalia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 16:32:22 by lkavalia          #+#    #+#             */
/*   Updated: 2023/05/22 13:33:18 by lkavalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAURCRAT_HPP
# define BUREAURCRAT_HPP

#include <iostream>
#include <exception>
#include <string>
#include "AForm.hpp"

class	AForm;

class	Bureaucrat
{
	public:
		//Canonical-form	---------->
		Bureaucrat(void);
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat& other);
		~Bureaucrat(void);

		Bureaucrat&	operator=(const Bureaucrat& other);

		//Getters	------------------>
		std::string			getName(void) const;
		int					getGrade(void) const;

		//Member functions	---------->
		void	incrementGrade(void);
		void	decrementGrade(void);
		void	checkGrade(int& grade) const;
		void	executeForm(AForm const & form);
		void	signForm(AForm& form, const std::string reason) const;
		
		//Exception classes ---------->
		class	GradeTooHighException: public std::exception
		{
		public:
			virtual const char	*what() const throw();
		};

		class	GradeTooLowException: public std::exception
		{
		public:
			virtual const char	*what() const throw();
		};
	private:
		const std::string	_name;
		int					_grade;		
};

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& obj);

# define	BLANK "\033[0m"
# define	RED	"\033[0;31m"
# define	GREEN "\033[0;32m"
# define	YELL "\033[0;33m"
# define	CYAN "\033[0;36m"

#endif