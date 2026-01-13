/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thodavid <thodavid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 10:59:02 by thodavid          #+#    #+#             */
/*   Updated: 2026/01/12 11:33:19 by thodavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("PresidentialPardonForm", 25, 5), _target("NO_NAME")
{
    std::cout << C_DGRAY << "Hello from the PresidentialPardonForm ctor default" << C_RESET << '\n';
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
    std::cout << C_DGRAY << "Hello from the PresidentialPardonForm ctor by param" << C_RESET << '\n';
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src) : AForm(src), _target(src._target)
{
    std::cout << C_DGRAY << "Hello from the PresidentialPardonForm ctor by cpy" << C_RESET << '\n';
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &rightHandSide)
{
    std::cout << C_DGRAY << "Copy assignment PresidentialPardonForm operator called" << '\n';
    if (this != &rightHandSide)
    {
        AForm::operator=(rightHandSide);
        this->_target = rightHandSide._target;
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << C_DGRAY << "Hello from the PresidentialPardonForm dtor " << C_RESET << '\n';
}

void PresidentialPardonForm::form_action(void) const
{
    std::cout << C_BLUE << "information: " << '\n'
              << this->_target << " has been pardoned by Zaphod Beeblebrox." << C_RESET << '\n';
}
