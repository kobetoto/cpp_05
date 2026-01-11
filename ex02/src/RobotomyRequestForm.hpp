/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thodavid <thodavid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 10:59:15 by thodavid          #+#    #+#             */
/*   Updated: 2026/01/11 15:06:08 by thodavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <string>
#include <iostream>
#include <stdexcept>
#include <cstdlib> //rand()
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
private:
    std::string _target; // no const (no const in the subject + no const for operator=)
protected:
    void form_action(void) const;

public:
    RobotomyRequestForm(void);
    RobotomyRequestForm(const std::string &target);
    RobotomyRequestForm(RobotomyRequestForm const &src);
    RobotomyRequestForm &operator=(RobotomyRequestForm const &rightHandSide);
    ~RobotomyRequestForm();
};

#endif // ROBOTOMYREQUESTFORM_HPP
