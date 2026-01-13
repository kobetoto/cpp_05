/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thodavid <thodavid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 10:37:47 by thodavid          #+#    #+#             */
/*   Updated: 2026/01/12 13:44:22 by thodavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <stdexcept>
#include "Colors.hpp"

class AForm;

class Bureaucrat
{
private:
    const std::string _name;
    int _grade;

public:
    Bureaucrat(void);                                       //(c) CTOR default
    Bureaucrat(const std::string &name, int grade);       //(c) CTOR by param
    Bureaucrat(Bureaucrat const &src);                      //(c) CTOR by copy
    Bureaucrat &operator=(Bureaucrat const &rightHandSide); //(c) Copy assignment_oper
    ~Bureaucrat(void);                                      //(c) destr

    void signForm(AForm &form) const;
    void executeForm(AForm const & form) const;

    const std::string &getName(void) const;
    int getGrade(void) const;

    void increment_grade(void);
    void decrement_grade(void);

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

std::ostream &operator<<(std::ostream &stream, Bureaucrat const &rightHandSide);

#endif // BUREAUCRAT_HPP
