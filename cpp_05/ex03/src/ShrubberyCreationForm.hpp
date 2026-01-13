/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thodavid <thodavid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 10:59:22 by thodavid          #+#    #+#             */
/*   Updated: 2026/01/11 14:06:59 by thodavid         ###   ########.fr       */
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
protected:
    void form_action( void ) const;
public:
    ShrubberyCreationForm(void);
    ShrubberyCreationForm(const std::string &target);
    ShrubberyCreationForm(ShrubberyCreationForm const &src);
    ShrubberyCreationForm &operator=(ShrubberyCreationForm const &rightHandSide);
    ~ShrubberyCreationForm();
};

#endif // SHRUBBERYCREATIONFORM_HPP
