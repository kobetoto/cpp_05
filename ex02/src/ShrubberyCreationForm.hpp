/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thodavid <thodavid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 10:59:22 by thodavid          #+#    #+#             */
/*   Updated: 2026/01/10 17:02:11 by thodavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <string>
#include <iostream>
#include <stdexcept>
#include <fstream> 
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
private:
    std::string _target; // no const (no const in the subject + no const for operator=)
    
    public:
    ShrubberyCreationForm(void);
    ShrubberyCreationForm(const std::string &target);
    ShrubberyCreationForm(ShrubberyCreationForm const &src);
    ShrubberyCreationForm &operator=(ShrubberyCreationForm const &rightHandSide);
    ~ShrubberyCreationForm();

    void form_action(const std::string target);
};

#endif // SHRUBBERYCREATIONFORM_HPP
