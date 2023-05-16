/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkavalia <lkavalia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 16:32:22 by lkavalia          #+#    #+#             */
/*   Updated: 2023/05/15 14:04:51 by lkavalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAURCRAT_HPP
# define BUREAURCRAT_HPP

#include <iostream>
#include <string>

class	Bureaucrat
{
	public:
		//Canonical-form	---------->
		Bureaucrat(void);
		Bureaucrat(const Bureaucrat& other);
		~Bureaucrat(void);

		Bureaucrat&	operator=(const Bureaucrat& other);

		//Getters	------------------>
		std::string			getName(void) const;
		int					getGrade(void) const;

		//Member functions	---------->
		void	incrementGrade(void);
		void	decrementGrade(void);
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