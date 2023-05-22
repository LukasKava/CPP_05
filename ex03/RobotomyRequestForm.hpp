/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkavalia <lkavalia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 11:40:43 by lkavalia          #+#    #+#             */
/*   Updated: 2023/05/22 11:38:03 by lkavalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	ROBOTOMYREQUESTFORM_HPP
# define	ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include "cstdlib"

class	RobotomyRequestForm: public AForm
{
	public:
		//Canonical form	----------------------------------->
		RobotomyRequestForm(void);
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm& other);
		~RobotomyRequestForm(void);
		
		RobotomyRequestForm&	operator=(const RobotomyRequestForm& other);
		
		//Getters	--------------------------------------->
		std::string	getTarget(void) const;

		//Member functions	----------------------------------->
		bool	execute(Bureaucrat const & executor)	const;
	private:
		std::string	_target;
};

#endif