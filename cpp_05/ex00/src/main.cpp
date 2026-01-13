/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thodavid <thodavid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 10:24:17 by thodavid          #+#    #+#             */
/*   Updated: 2026/01/09 14:13:52 by thodavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{

	std::cout << std::endl << "==TEST 1==" << std::endl;
	{
		Bureaucrat b("kobe", 24);
		std::cout << "Bureaucrat: " << b.getName() << std::endl
				  << "Grade: " << b.getGrade()
				  << std::endl
				  << std::endl;

		Bureaucrat noName;
		std::cout << "Bureaucrat: " << noName.getName() << std::endl
				  << "Grade: " << noName.getGrade()
				  << std::endl
				  << std::endl;

		Bureaucrat clone(b);
		std::cout << "Bureaucrat: " << clone.getName() << std::endl
				  << "Grade: " << clone.getGrade()
				  << std::endl
				  << std::endl;

		noName = clone;
		std::cout << "Bureaucrat: " << noName.getName() << std::endl
				  << "Grade: " << noName.getGrade()
				  << std::endl
				  << std::endl;
	}

	std::cout << std::endl << "==TEST 2==" << std::endl;
	{
		Bureaucrat kobe("Kobe", 24);
		try
		{
			Bureaucrat lebron("Lebron", 151);
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}

		std::cout << std::endl
				  << kobe << std::endl;
		std::cout << "==PROMOTION TIME==" << std::endl;
		try
		{
			for (int i = 0; i < 24; i++)
				kobe.increment_grade();
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	std::cout << std::endl << "==TEST 3==" << std::endl;
	{
		try
		{
			Bureaucrat shaq("Shaq", 1);
			std::cout << std::endl
					  << shaq << std::endl;
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
		try
		{
			Bureaucrat shaq("Shaq", 0);
			std::cout << std::endl
					  << shaq << std::endl;
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	return (0);
}
