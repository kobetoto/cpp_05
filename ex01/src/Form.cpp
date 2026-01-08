/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thodavid <thodavid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 11:51:08 by thodavid          #+#    #+#             */
/*   Updated: 2026/01/08 17:09:34 by thodavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void) : _name("NO_NAME"), _sign(false), _grd_to_exec(1), _grd_to_sign(1)
{
    std::cout << "Hello from the ctor default" << std::endl;
}

Form::Form(const std::string &name, bool sign,
           const int grd_to_sign,
           const int grd_to_exec) : _name(name), _sign(sign), _grd_to_exec(grd_to_exec), _grd_to_sign(grd_to_sign)
{
    std::cout << "Hello from the ctor default" << std::endl;

    if (_grd_to_exec > 150 || _grd_to_sign > 150)
        throw GradeTooLowException();
    if (_grd_to_exec < 1 || _grd_to_sign < 1)
        throw GradeTooHighException();
}

Form::Form(Form const &src) : _name(src._name), _sign(src._sign), _grd_to_exec(src._grd_to_exec), _grd_to_sign(src._grd_to_sign)
{
    std::cout << "Hello from the ctor by copy" << std::endl;
}

Form::~Form()
{
    std::cout << "Hello from the desctor" << std::endl;
}

/* OVERLOAD */

std::ostream &operator<<(std::ostream &stream, Form const &rightHandSide)
{
    stream << rightHandSide.getName()
           << " Form" << std::endl
           << "-> grade required to sign it: " << rightHandSide.get_grd_to_sign() << "."
           << std::endl
           << "-> grade required to execute it: " << rightHandSide.get_grd_to_sign() << ".";
    return stream;
}

Form &Form::operator=(Form const &rightHandSide)
{
    std::cout << "Copy assignment operator called" << '\n';
    if (this != &rightHandSide)
        this->_sign = rightHandSide._sign;

    return *this;
}

/* GETTERS */

const std::string &Form::getName(void) const { return (_name); }
int Form::get_grd_to_sign(void) const { return (_grd_to_sign); }
int Form::get_grd_to_exec(void) const { return (_grd_to_exec); }
bool Form::get_is_sign(void) const { return (_sign); }
