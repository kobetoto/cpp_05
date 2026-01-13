/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thodavid <thodavid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 10:24:17 by thodavid          #+#    #+#             */
/*   Updated: 2026/01/09 16:47:09 by thodavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	std::cout << std::endl
			  << "==TEST 1==" << std::endl;
	{
		try{
			Form form1("28C", 1000, 150);
		}
		catch(std::exception &e){
			std::cerr << e.what() << std::endl;
		}
	}

	{
		try{
			Form form2("42x", 1, -1);
		}
		catch(std::exception &e){
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << "(No obj construct (so no dtor call))" << std::endl;

	std::cout << std::endl
			  << "==TEST 2==" << std::endl;
	{
		Bureaucrat b("kobe", 24);
		Form form1("28C", 150, 150);
		Form form2("42x", 1, 1);
		b.signForm(form1);
		b.signForm(form2);
	}
	return (0);
}
