/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkavalia <lkavalia@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 11:45:14 by lkavalia          #+#    #+#             */
/*   Updated: 2023/05/18 14:51:16 by lkavalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PRESIDENTIALPARDONFORM_HPP
# define	PRESIDENTIALPARDONFORM_HPP

#include "Bureaucrat.hpp"
#include "AForm.hpp"

class	PresidentialPardonForm : public AForm
{
	public:
		//Canonical for	----------------------------------->
		PresidentialPardonForm(void);
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm& other);
		~PresidentialPardonForm(void);
		
		PresidentialPardonForm&	operator=(const PresidentialPardonForm& other);

		//Getters	--------------------------------------->
		std::string	getTarget(void) const;

		//Member function	------------------------------->
		void	execute(Bureaucrat const & executor)	const;
	private:
		std::string	_target;
};

#endif