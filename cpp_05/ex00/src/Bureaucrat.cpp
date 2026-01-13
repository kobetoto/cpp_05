/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thodavid <thodavid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 10:37:44 by thodavid          #+#    #+#             */
/*   Updated: 2026/01/12 09:54:23 by thodavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/* CANONICAL FORM (CTOR)*/

Bureaucrat::Bureaucrat(void) : _name("NO-NAME"), _grade(150)
{
	std::cout << "Hello from the ctor default" << '\n';
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name), _grade(150)
{
	std::cout << "Hello from the ctor by param" << '\n';

	if (grade > 150)
		throw GradeTooLowException();
	if (grade < 1)
		throw GradeTooHighException();
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const &src) : _name(src._name), _grade(src._grade)
{
	std::cout << "Hello from the ctor by copy" << '\n';
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &rightHandSide)
{
	std::cout << "Copy assignment operator called" << '\n';
	if (this != &rightHandSide)
		this->_grade = rightHandSide._grade;
	return *this;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Hello from the desctor" << '\n';
}

/* GETTERS */

const std::string & Bureaucrat::getName(void) const { return (this->_name); }

int Bureaucrat::getGrade(void) const { return (this->_grade); }

/* OVERLOAD */

std::ostream &operator<<(std::ostream &stream, Bureaucrat const &rightHandSide) //    (surcharge) operateur d'assignation <<
{
	stream << rightHandSide.getName()
		   << ", bureaucrat grade " << rightHandSide.getGrade() << ".";
	return stream;
}

/* inc/dec GRADE */

void Bureaucrat::increment_grade(void)
{
	if (this->_grade == 1)
		throw GradeTooHighException();
	--_grade;
}

void Bureaucrat::decrement_grade(void)
{
	if (this->_grade == 150)
		throw GradeTooLowException();
	++_grade;
}
