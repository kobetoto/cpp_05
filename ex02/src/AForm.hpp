/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thodavid <thodavid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 11:51:17 by thodavid          #+#    #+#             */
/*   Updated: 2026/01/10 16:58:09 by thodavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <iostream>
#include <stdexcept>

class Bureaucrat;

class AForm
{
private:
    const std::string _name;
    bool _sign;
    const int _grd_to_sign;
    const int _grd_to_exec;

public:
    AForm(void); //(c) CTOR default
    AForm(const std::string &name,              //(c) CTOR by param
         const int grd_to_sign,
         const int grd_to_exec);
    AForm(AForm const &src);                      //(c) CTOR by copy
    AForm &operator=(AForm const &rightHandSide); //(c) Copy assignment_oper
    virtual ~AForm(void);                                //(c) destr

    void virtual form_action (const std::string target) = 0;
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

std::ostream &operator<<(std::ostream &stream, AForm const &rhs);

#endif // AFORM_HPP
