/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thodavid <thodavid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 10:59:11 by thodavid          #+#    #+#             */
/*   Updated: 2026/01/11 15:21:53 by thodavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("RobotomyRequestForm", 72, 45), _target("NO_NAME")
{
    std::cout << "Hello from the RobotomyRequestForm ctor default" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
    std::cout << "Hello from the RobotomyRequestForm ctor by param" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src) : AForm(src), _target(src._target)
{
    std::cout << "Hello from the RobotomyRequestForm ctor by cpy" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &rightHandSide)
{
    std::cout << "Copy assignment RobotomyRequestForm operator called" << '\n';
    if (this != &rightHandSide)
    {
        AForm::operator=(rightHandSide);
        this->_target = rightHandSide._target;
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "Hello from the RobotomyRequestForm dtor " << std::endl;
}

void RobotomyRequestForm::form_action(void) const{
    int r = std::rand();
    if(r % 2)
    {
        std::cout << "BrrrBrrrrrr" << std::endl
        << "information: "<< std::endl 
        << this->_target << " has been robotomized" 
        << std::endl;
    }
    else 
    {
        std::cout << "information: " << "the robotomy failed" << std::endl;
    }
}
