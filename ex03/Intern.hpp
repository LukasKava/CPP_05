/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkavalia <lkavalia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 12:33:05 by lkavalia          #+#    #+#             */
/*   Updated: 2023/05/22 13:55:49 by lkavalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class   Intern
{
    public:
        //Canonical-form	---------->
        Intern(void);
        Intern(const Intern& other);
        ~Intern(void);
        
        Intern& operator=(const Intern& other);

        //Member functions	---------->
		AForm	*makeForm(std::string form_name, std::string target)	const;
};

#endif