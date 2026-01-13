/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thodavid <thodavid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 12:25:50 by thodavid          #+#    #+#             */
/*   Updated: 2026/01/12 14:59:31 by thodavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void)
{
    std::cout << C_DGRAY << "Hello from the ctor default" << C_RESET << '\n';
}
Intern::Intern(const Intern &src)
{
    (void)src;
    std::cout << C_DGRAY << "Hello from the Aform ctor by copy" << C_RESET << '\n';
}
Intern &Intern::operator=(const Intern &rhs)
{
    (void)rhs;
    std::cout << C_DGRAY << "Copy assignment operator called" << C_RESET << '\n';
    return *this;
}

Intern::~Intern()
{
    std::cout << C_DGRAY << "Hello from the Intern desctor" << C_RESET << '\n';
}

AForm *Intern::createPresidential(const std::string &target)
{
    return (new PresidentialPardonForm(target));
}

AForm *Intern::createRobotomy(const std::string &target)
{
    return (new RobotomyRequestForm(target));
}

AForm *Intern::createShrubbery(const std::string &target)
{
    return (new ShrubberyCreationForm(target));
}

AForm *Intern::makeForm(const std::string &Name_form, const std::string &target) const
{
    const std::string names[3] = {
        "presidential pardon",
        "robotomy request",
        "shrubbery creation"
    };

    t_form f_create[3] = {
        &Intern::createPresidential,
        &Intern::createRobotomy,
        &Intern::createShrubbery
    };

    int i = 0;
    while(i < 3){
        if (names[i] == Name_form)
        {
            std::cout << C_BLUE << "Intern creates " << Name_form << C_RESET << '\n';
            return (f_create[i](target));
        }
        i++;
    }
    std::cout << C_RED << "Intern can creates the form (form doesnt exist please contact a Bureaucrat)" << C_RESET << '\n';
    return (NULL);
}
