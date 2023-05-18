/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkavalia <lkavalia@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 11:25:24 by lkavalia          #+#    #+#             */
/*   Updated: 2023/05/18 11:39:49 by lkavalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include	"AForm.hpp"

class	SchrubberyCreationForm: public	AForm
{
	public:
		//Canonical for	----------------------------------->
		SchrubberyCreationForm(void);
		SchrubberyCreationForm(std::string& target);
		SchrubberyCreationForm(const SchrubberyCreationForm& other);
		~SchrubberyCreationForm(void);
		
		SchrubberyCreationForm&	operator=(const SchrubberyCreationForm& other);
	private:
		std::string	_target;
};

#endif