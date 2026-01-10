/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thodavid <thodavid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 10:59:19 by thodavid          #+#    #+#             */
/*   Updated: 2026/01/10 17:39:22 by thodavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : _target("NO_NAME")
{
    std::cout << "Hello from the ShrubberyCreationForm ctor default" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : _target(target)
{
    std::cout << "Hello from the ShrubberyCreationForm ctor by param" << std::endl;
}
ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src) : _target(src._target)
{
    std::cout << "Hello from the ShrubberyCreationForm ctor by cpy" << std::endl;
}

void ShrubberyCreationForm::form_action(const std::string target)
{
    std::string fileName = target + "_shrubbery";
    std::ofstream o(fileName.c_str());

o <<
"             /\\\n"
"            <  >\n"
"             \\/\n"
"             /\\\n"
"            /  \\\n"
"           /++++\\\n"
"          /  ()  \\\n"
"          /      \\\n"
"         /~`~`~`~`\\\n"
"        /  ()  ()  \\\n"
"        /          \\\n"
"       /*&*&*&*&*&*&\\\n"
"      /  ()  ()  ()  \\\n"
"      /              \\\n"
"     /++++++++++++++++\\\n"
"    /  ()  ()  ()  ()  \\\n"
"    /                  \\\n"
"   /~`~`~`~`~`~`~`~`~`~`\\\n"
"  /  ()  ()  ()  ()  ()  \\\n"
"  /*&*&*&*&*&*&*&*&*&*&*&\\\n"
" /                        \\\n"
"/,.,.,.,.,.,.,.,.,.,.,.,.,.\\\n"
"           |   |\n"
"          |`````|\n"
"          \\_____/\n"
<< std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rightHandSide)
{
    std::cout << "Copy assignment operator called" << '\n';
    if (this != &rightHandSide)
        this->_target = rightHandSide._target;

    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "Hello from the ShrubberyCreationForm dtor " << std::endl;
}
