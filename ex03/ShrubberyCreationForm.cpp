/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkavalia <lkavalia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 23:15:42 by lkavalia          #+#    #+#             */
/*   Updated: 2023/05/22 11:42:13 by lkavalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

//Canonical for	--------------------------------------------------------------->
ShrubberyCreationForm::ShrubberyCreationForm(void): AForm("Shrubbery Creation", 145, 137), _target("Maxus")
{
	std::cout << GREEN "SHRUBBERY CREATION" BLANK << " default constructor has been called!" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("Shrubbery Creation", 145, 137), _target(target)
{
	std::cout << GREEN "SHRUBBERY CREATION" BLANK << " constructor has been called!" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other): AForm(other.getName(), other.getMinGradeToSign(), other.getMinGradeToExecute())
{
	std::cout << GREEN "SHRUBBERY CREATION" BLANK << " copy constructor has been called!" << std::endl;
	*this = other;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << RED "SHRUBBERY CREATION" BLANK << " destructor has been called!" << std::endl;
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	std::cout << GREEN "SHRUBBERY CREATION" BLANK << " equal assignment operator overload has been called!" << std::endl;
	this->copy_form_status(other.getForm());
	_target = other._target;
	return	(*this);
}

//Getters	------------------------------------------------------------->
std::string	ShrubberyCreationForm::getTarget(void) const
{
	return (_target);
}

//Member functions	------------------------------------------------------>
bool	ShrubberyCreationForm::execute(Bureaucrat const & executor)const
{
	if (this->checkExecRequirements(executor) == false)
		return (false);
	std::string		file_name = _target + "_shrubbery";
    std::ofstream   out_file(file_name.c_str());
    if (out_file.is_open())
    {
        out_file << "           .        +          .      .          .		" << std::endl;
        out_file << "     .            _        .                    . 		" << std::endl;
        out_file << "  ,              /;-._,-.____        ,-----.__    		" << std::endl;
        out_file << " ((        .    (_:#::_.:::. `-._   /:, /-._, `._,		" << std::endl;
        out_file << "  `                     _|`=:_::.`.    _          		" << std::endl;
        out_file << "                      ,    `./   :. `.   )==-'  . 		" << std::endl;
        out_file << "    .      ., ,-=-.  , , +#./`    :.  / /         		" << std::endl;
        out_file << ".            /:/`-' , ,  '` ` `   ): , /_  -o	   		" << std::endl;
        out_file << "       .    /:+- - + +- : :- + + -:'  /(o-)  )    		" << std::endl;
        out_file << "  .      ,=':       ` `/` ' , , ,:' `'-- .-- ---._/`7	" << std::endl;
        out_file << "   `.   (     :  ,-._` ` + ' , ,    _,--._,--- :.__/ 	" << std::endl;
        out_file << "               :  `  X` _| _, /'   .-'				  	" << std::endl;
        out_file << ".                :._:` ____  /:'  /      .           	" << std::endl;
        out_file << "                     ::.  : /:'  /              +	  	" << std::endl;
        out_file << "   .                 `.:.  /:'  }      .			  	" << std::endl;
        out_file << "           .           ):_(:;               .		  	" << std::endl;
        out_file << "                      /:. _/ ,  |					  	" << std::endl;
        out_file << "                   . (|::.     ,`                  . 	" << std::endl;
        out_file << "     .                |::.    { 					  	" << std::endl;
        out_file << "                      |::.     `.					  	" << std::endl;
        out_file << "                      |:::(     |					  	" << std::endl;
        out_file << "              O       |:::/{ }  |                  (o	" << std::endl;
        out_file << "               )  ___/# ::`/ (O  ==._____   O, (O  /`	" << std::endl;
        out_file << "          ~~~w/w~ ~~, ` `:/,-(~` ~~~~~~~~ ~o~ ~/~w|/~	" << std::endl;
        out_file << "     ~~~~~~~~~~~~~~~~~~~~~~~ W~~~~~~~~~~~~ |/~~	  	" << std::endl;
        out_file.close();
    }
    else std::cout << RED "Unable to open file" BLANK << std::endl;
	return (true);
}