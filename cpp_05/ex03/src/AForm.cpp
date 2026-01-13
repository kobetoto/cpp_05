/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thodavid <thodavid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 11:51:08 by thodavid          #+#    #+#             */
/*   Updated: 2026/01/09 16:42:57 by thodavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(void) : _name("NO_NAME"), _sign(false), _grd_to_sign(1), _grd_to_exec(1)
{
    std::cout << C_DGRAY << "Hello from the ctor default" << C_RESET << '\n';
}

AForm::AForm(const std::string &name,
             const int grd_to_sign,
             const int grd_to_exec) : _name(name), _sign(false), _grd_to_sign(grd_to_sign), _grd_to_exec(grd_to_exec)
{
    std::cout  << C_DGRAY << "Hello from the Aform ctor param" << C_RESET << '\n';

    if (_grd_to_exec > 150 || _grd_to_sign > 150)
        throw GradeTooLowException();
    if (_grd_to_exec < 1 || _grd_to_sign < 1)
        throw GradeTooHighException();
}

AForm::AForm(AForm const &src) : _name(src._name), _sign(src._sign), _grd_to_sign(src._grd_to_sign), _grd_to_exec(src._grd_to_exec)
{
    std::cout  << C_DGRAY << "Hello from the Aform ctor by copy" << C_RESET << '\n';
}

AForm::~AForm()
{
    std::cout  << C_DGRAY << "Hello from the Aform desctor" << C_RESET << '\n';
}

/* OVERLOAD */

std::ostream &operator<<(std::ostream &stream, AForm const &rightHandSide)
{
    stream << rightHandSide.getName()
           << C_GREEN
           << " AForm" << '\n'
           << "-> grade required to sign it: " << rightHandSide.get_grd_to_sign() << "."
           << '\n'
           << "-> grade required to execute it: " << rightHandSide.get_grd_to_exec() << "." << C_RESET << '\n';
    return stream;
}

AForm &AForm::operator=(AForm const &rightHandSide)
{
    std::cout  << C_DGRAY << "Copy assignment operator called" << C_RESET << '\n';
    if (this != &rightHandSide)
        this->_sign = rightHandSide._sign;

    return *this;
}

/* GETTERS */

const std::string &AForm::getName(void) const { return (_name); }
int AForm::get_grd_to_sign(void) const { return (_grd_to_sign); }
int AForm::get_grd_to_exec(void) const { return (_grd_to_exec); }
bool AForm::get_is_sign(void) const { return (_sign); }

/* beSigned */

void AForm::beSigned(const Bureaucrat &b)
{
    if (b.getGrade() <= this->get_grd_to_sign())
        _sign = true;
    else
        throw GradeTooLowException();
}

void AForm::execute(Bureaucrat const &executor) const
{
    if (!this->get_is_sign())
        throw FormNotSignException();

    if (executor.getGrade() > this->get_grd_to_exec())
        throw GradeTooLowException();

    this->form_action();
}
