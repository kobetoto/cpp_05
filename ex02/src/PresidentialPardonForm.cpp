/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thodavid <thodavid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 10:59:02 by thodavid          #+#    #+#             */
/*   Updated: 2026/01/10 17:00:36 by thodavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : _target("NO_NAME")
{
    std::cout << "Hello from the PresidentialPardonForm ctor default" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : _target(target)
{
    std::cout << "Hello from the PresidentialPardonForm ctor by param" << std::endl;
}
PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src) : _target(src._target)
{
    std::cout << "Hello from the PresidentialPardonForm ctor by cpy" << std::endl;
}

void PresidentialPardonForm::form_action(const std::string target)
{
    std::cout << "HELLO THERE " << target << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &rightHandSide)
{
    std::cout << "Copy assignment operator called" << '\n';
    if (this != &rightHandSide)
        this->_target = rightHandSide._target;

    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "Hello from the PresidentialPardonForm dtor " << std::endl;
}
