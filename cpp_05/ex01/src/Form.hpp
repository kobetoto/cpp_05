/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thodavid <thodavid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 11:51:17 by thodavid          #+#    #+#             */
/*   Updated: 2026/01/09 14:49:35 by thodavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>
#include <stdexcept>

class Bureaucrat;

class Form
{
private:
    const std::string _name;
    bool _sign;
    const int _grd_to_sign;
    const int _grd_to_exec;

public:
    Form(void); //(c) CTOR default
    Form(const std::string &name,              //(c) CTOR by param
         const int grd_to_sign,
         const int grd_to_exec);
    Form(Form const &src);                      //(c) CTOR by copy
    Form &operator=(Form const &rightHandSide); //(c) Copy assignment_oper
    ~Form(void);                                //(c) destr

    void beSigned(const Bureaucrat &b);

    const std::string &getName(void) const;
    int get_grd_to_sign(void) const;
    int get_grd_to_exec(void) const;
    bool get_is_sign(void) const;

    class GradeTooLowException : public std::exception
    {
    public:
        const char *what() const throw()
        {
            return "Grade is too low";
        }
    };

    class GradeTooHighException : public std::exception
    {
    public:
        const char *what() const throw()
        {
            return "Grade is too high";
        }
    };
};

std::ostream &operator<<(std::ostream &stream, Form const &rhs);

#endif // FORM_HPP
