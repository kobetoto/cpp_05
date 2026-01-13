/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thodavid <thodavid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 10:37:44 by thodavid          #+#    #+#             */
/*   Updated: 2026/01/13 15:39:00 by thodavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

/* CANONICAL FORM (CTOR)*/

Bureaucrat::Bureaucrat(void) : _name("NO_NAME"), _grade(150)
{
	std::cout << C_DGRAY << "Hello from the Bureaucrat ctor default" << C_RESET << '\n';
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name), _grade(150)
{
	std::cout << C_DGRAY << "Hello from the Bureaucrat ctor by param" << C_RESET << '\n';

	if (grade > 150)
		throw GradeTooLowException();
	if (grade < 1)
		throw GradeTooHighException();
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const &src) : _name(src._name), _grade(src._grade)
{
	std::cout << C_DGRAY << "Hello from the Bureaucrat ctor by copy" << C_RESET << '\n';
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &rightHandSide)
{
	std::cout << C_DGRAY << "Copy assignment operator called" << C_RESET << '\n';
	if (this != &rightHandSide)
		this->_grade = rightHandSide._grade;
	return *this;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << C_DGRAY << "Hello from the Bureaucrat desctor" << C_RESET << '\n';
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

void Bureaucrat::signForm(AForm &form) const
{
    try {
        form.beSigned(*this);
        std::cout << C_GREEN << this->getName() << " signed " << form.getName() <<  C_RESET << '\n';
    } catch (const std::exception &e) {
        std::cout << C_RED << this->getName() << " couldn’t sign " << form.getName()
                  << " because " << e.what() << C_RESET << '\n';
    }
}

void Bureaucrat::executeForm(AForm const &form) const
{
    try {
        form.execute(*this);
        std::cout << this->getName() << " executed " << form.getName() << '\n';
    } catch (const std::exception &e){
        std::cerr << this->getName() << " couldn’t execute " << form.getName()
                  << " because " << e.what() << '\n';
    }
}
