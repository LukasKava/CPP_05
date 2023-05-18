/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkavalia <lkavalia@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 11:40:43 by lkavalia          #+#    #+#             */
/*   Updated: 2023/05/18 11:44:55 by lkavalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	ROBOTOMYREQUESTFORM_HPP
# define	ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class	RobotomyRequestForm: public AForm
{
	public:
		//Canonical for	----------------------------------->
		RobotomyRequestForm(void);
		RobotomyRequestForm(std::string& target);
		RobotomyRequestForm(const RobotomyRequestForm& other);
		~RobotomyRequestForm(void);
		
		RobotomyRequestForm&	operator=(const RobotomyRequestForm& other);
	private:
		std::string	_target;
};

#endif