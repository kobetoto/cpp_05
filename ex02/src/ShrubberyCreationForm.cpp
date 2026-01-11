/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thodavid <thodavid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 10:59:19 by thodavid          #+#    #+#             */
/*   Updated: 2026/01/11 12:56:54 by thodavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("ShrubberyCreationForm", 145, 137), _target("NO_NAME")
{
    std::cout << "Hello from the ShrubberyCreationForm ctor default" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
    std::cout << "Hello from the ShrubberyCreationForm ctor by param" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src) : AForm(src), _target(src._target)
{
    std::cout << "Hello from the ShrubberyCreationForm ctor by cpy" << std::endl;
}

void ShrubberyCreationForm::form_action(void) const
{
    std::string fileName = this->_target + "_shrubbery";
    std::ofstream o(fileName.c_str());
    if (!o.is_open())
        throw std::exception();
    o << "             /\\\n"
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
      << std::endl
      << "             /\\\n"
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
    {
        AForm::operator=(rightHandSide);
        this->_target = rightHandSide._target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "Hello from the ShrubberyCreationForm dtor " << std::endl;
}
