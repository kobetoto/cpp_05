/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thodavid <thodavid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 12:25:44 by thodavid          #+#    #+#             */
/*   Updated: 2026/01/12 14:58:37 by thodavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include <iostream>
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Colors.hpp"


class Intern
{
private:
    typedef AForm* (*t_form)(const std::string &name);

    static AForm* createPresidential(const std::string& target);
    static AForm* createRobotomy(const std::string& target);
    static AForm* createShrubbery(const std::string& target);

public:
    Intern();
    Intern(const Intern& src);
    Intern& operator=(const Intern& rhs);
    ~Intern();

    AForm* makeForm(const std::string& name_form, const std::string& target) const;
};

#endif //INTERN_HPP
