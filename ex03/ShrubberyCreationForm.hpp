/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkavalia <lkavalia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 11:25:24 by lkavalia          #+#    #+#             */
/*   Updated: 2023/05/22 11:40:32 by lkavalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include	"AForm.hpp"
#include	<fstream>

class	ShrubberyCreationForm: public	AForm
{
	public:
		//Canonical for	----------------------------------->
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm& other);
		~ShrubberyCreationForm(void);
		
		ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& other);

		//Getters	--------------------------------------->
		std::string	getTarget(void) const;

		//Member functions	----------------------------------->
		bool	execute(Bureaucrat const & executor)	const;
	private:
		std::string	_target;
};

#endif