/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thodavid <thodavid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 10:59:02 by thodavid          #+#    #+#             */
/*   Updated: 2026/01/11 15:22:55 by thodavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("PresidentialPardonForm", 25, 5), _target("NO_NAME")
{
    std::cout << "Hello from the PresidentialPardonForm ctor default" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
    std::cout << "Hello from the PresidentialPardonForm ctor by param" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src) : AForm(src), _target(src._target)
{
    std::cout << "Hello from the PresidentialPardonForm ctor by cpy" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &rightHandSide)
{
    std::cout << "Copy assignment PresidentialPardonForm operator called" << '\n';
    if (this != &rightHandSide)
    {
        AForm::operator=(rightHandSide);
        this->_target = rightHandSide._target;
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "Hello from the PresidentialPardonForm dtor " << std::endl;
}

void PresidentialPardonForm::form_action(void) const
{
    std::cout << "information: " << std::endl
              << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
