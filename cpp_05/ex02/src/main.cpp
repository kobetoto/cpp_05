/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thodavid <thodavid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 10:24:17 by thodavid          #+#    #+#             */
/*   Updated: 2026/01/12 16:26:14 by thodavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include <cstdlib> //rand()
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	std::srand(std::time(NULL)); // for rand()

	std::cout << "\n"
			  << C_BOLD << "==TEST 1==" << C_RESET << "\n"
			  << "\n";
	{
		Bureaucrat b("kobe", 24);
		ShrubberyCreationForm form1("newFile");
		b.signForm(form1);
		form1.execute(b);
	}

	std::cout << "\n"
			  << C_BOLD << "==TEST 2==" << C_RESET << "\n"
			  << "\n";

	AForm *form = 0;
	try
	{
		form = new RobotomyRequestForm("Test");
		Bureaucrat b("kobe", 1);
		b.signForm(*form);
		form->execute(b);
		delete form;
	}
	catch (std::exception &e)
	{
		delete form;
		std::cerr << C_RED << e.what() << C_RESET << "\n";
	}

	std::cout << "\n"
			  << C_BOLD << "==TEST 3==" << C_RESET << "\n"
			  << "\n";
	{
		try
		{
			PresidentialPardonForm form("Arthur Dent");
			Bureaucrat b("kobe", 1);

			b.signForm(form);
			form.execute(b); 
		}
		catch (std::exception &e)
		{
			std::cerr << C_RED << e.what() << C_RESET << "\n";
		}
	}
	return (0);
}
