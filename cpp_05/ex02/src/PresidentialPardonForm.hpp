/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thodavid <thodavid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 10:59:07 by thodavid          #+#    #+#             */
/*   Updated: 2026/01/12 13:44:29 by thodavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <string>
#include <iostream>
#include <stdexcept>
#include "AForm.hpp"
#include "Colors.hpp"


class PresidentialPardonForm : public AForm
{
private:
    std::string _target; //no const (no const in the subject + no const for operator=)
protected:
    void form_action ( void ) const;
public:
    PresidentialPardonForm(void);
    PresidentialPardonForm(const std::string &target);
    PresidentialPardonForm(PresidentialPardonForm const &src);
    PresidentialPardonForm &operator=(PresidentialPardonForm const &rightHandSide);
    ~PresidentialPardonForm();
};

#endif //PRESIDENTIALPARDONFORM_HPP
