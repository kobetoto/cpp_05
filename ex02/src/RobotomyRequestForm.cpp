/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thodavid <thodavid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 10:59:11 by thodavid          #+#    #+#             */
/*   Updated: 2026/01/10 17:00:28 by thodavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"


RobotomyRequestForm::RobotomyRequestForm(void) : _target("NO_NAME")
{
    std::cout << "Hello from the RobotomyRequestForm ctor default" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : _target(target)
{
    std::cout << "Hello from the RobotomyRequestForm ctor by param" << std::endl;
}
RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src) : _target(src._target){
    std::cout << "Hello from the RobotomyRequestForm ctor by cpy" << std::endl;
}

void RobotomyRequestForm::form_action(const std::string target)
{
    std::cout << "HELLO THERE " << target << std::endl;

}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &rightHandSide){
    std::cout << "Copy assignment operator called" << '\n';
    if (this != &rightHandSide)
        this->_target = rightHandSide._target;

    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "Hello from the RobotomyRequestForm dtor " << std::endl;
}
