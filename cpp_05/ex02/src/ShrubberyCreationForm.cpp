/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thodavid <thodavid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 10:59:19 by thodavid          #+#    #+#             */
/*   Updated: 2026/01/12 11:03:11 by thodavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("ShrubberyCreationForm", 145, 137), _target("NO_NAME")
{
    std::cout << C_DGRAY << "Hello from the ShrubberyCreationForm ctor default" << C_RESET << '\n';
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
    std::cout << C_DGRAY << "Hello from the ShrubberyCreationForm ctor by param" << C_RESET << '\n';
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src) : AForm(src), _target(src._target)
{
    std::cout << C_DGRAY << "Hello from the ShrubberyCreationForm ctor by cpy" << C_RESET << '\n';
}

void ShrubberyCreationForm::form_action(void) const
{
    std::string fileName = this->_target + "_shrubbery";
    std::ofstream o(fileName.c_str());
    if (!o.is_open())
        throw std::runtime_error("Open file failed");
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
    std::cout << C_DGRAY << "Hello from the ShrubberyCreationForm dtor " << C_RESET << '\n';
}
