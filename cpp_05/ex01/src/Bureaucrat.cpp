/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thodavid <thodavid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 10:37:44 by thodavid          #+#    #+#             */
/*   Updated: 2026/01/09 16:52:54 by thodavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

/* CANONICAL FORM (CTOR)*/

Bureaucrat::Bureaucrat(void) : _name("NO_NAME"), _grade(150)
{
	std::cout << "Hello from the Bureaucrat ctor default" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name), _grade(150)
{
	std::cout << "Hello from the Bureaucrat ctor by param" << std::endl;

	if (grade > 150)
		throw GradeTooLowException();
	if (grade < 1)
		throw GradeTooHighException();
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const &src) : _name(src._name), _grade(src._grade)
{
	std::cout << "Hello from the Bureaucrat ctor by copy" << std::endl;
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
	std::cout << "Hello from the Bureaucrat desctor" << std::endl;
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

// void Bureaucrat::signForm(Form &form){
// 	try{
// 		form.beSigned(*this);
// 		if(form.get_is_sign()){
// 			std::cout << this->getName() << " signed " << form.getName() << std::endl;
// 			return;
// 		}
// 		else{
// 			std::cout << this->getName() <<" couldn’t sign "
// 			<< form.getName() <<" because ";
// 			throw GradeTooLowException();
// 		}
// 	}
// 	catch(std::exception &e){
// 		std::cerr  << e.what() << std::endl;
// 	}
// }

void Bureaucrat::signForm(Form &form) const
{
    try {
        form.beSigned(*this);
        std::cout << _name << " signed " << form.getName() << std::endl;
    } catch (const std::exception &e) {
        std::cout << _name << " couldn’t sign " << form.getName()
                  << " because " << e.what() << std::endl;
    }
}
