/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thodavid <thodavid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 10:59:11 by thodavid          #+#    #+#             */
/*   Updated: 2026/01/12 11:34:21 by thodavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("RobotomyRequestForm", 72, 45), _target("NO_NAME")
{
    std::cout << C_DGRAY << "Hello from the RobotomyRequestForm ctor default" << C_RESET << '\n';
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
    std::cout << C_DGRAY << "Hello from the RobotomyRequestForm ctor by param" << C_RESET << '\n';
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src) : AForm(src), _target(src._target)
{
    std::cout << C_DGRAY << "Hello from the RobotomyRequestForm ctor by cpy" << C_RESET << '\n';
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &rightHandSide)
{
    std::cout << C_DGRAY << "Copy assignment RobotomyRequestForm operator called" << C_RESET << '\n';
    if (this != &rightHandSide)
    {
        AForm::operator=(rightHandSide);
        this->_target = rightHandSide._target;
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << C_DGRAY << "Hello from the RobotomyRequestForm dtor " << C_RESET << '\n';
}

void RobotomyRequestForm::form_action(void) const{
    int r = std::rand();
    std::cout << C_YELLOW << "~~BrrrBrrrrrr~~" << C_RESET << '\n';
    if(r % 2)
    {
        std::cout  << C_BLUE << "information: "<< '\n' 
        << this->_target << " has been robotomized" 
        << C_RESET << '\n';
    }
    else 
    {
        std::cout << C_RED <<"information: " << '\n' << "the robotomy failed" << C_RESET << '\n';
    }
}
