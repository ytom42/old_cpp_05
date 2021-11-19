/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytomiyos <ytomiyos@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 17:52:13 by ytomiyos          #+#    #+#             */
/*   Updated: 2021/11/19 20:41:09 by ytomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) :
 Form("PresidentialPardonForm", 25, 5), _target(target)
{
	if (this->test)
		std::cout << "PresidentialPardonForm Costructor Called(" << this->getName() << ")" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &copy) :
 Form("PresidentialPardonForm", 25, 5)
{
	if (this->test)
		std::cout << "PresidentialPardonForm Copy Constructor Called(" << this->getName() << ")" << std::endl;
	*this = copy;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	if (this->test)
		std::cout << "PresidentialPardonForm Destructor Called(" << this->getName() << ")" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &copy)
{
	if (this->test)
		std::cout << "PresidentialPardonForm Copy Assignment Called(" << copy.getName() << ")" << std::endl;
	return (*this);
}

std::string PresidentialPardonForm::getTarget() const
{
	return (this->_target);
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (this->test)
		std::cout << "PresidentialPardonForm Execute Called(" << this->getName() << ")" << std::endl;
	try {
		if (this->getSigned())
		{
			if (executor.getGrade() > this->getGradeExec())
				throw Form::GradeTooLowException();
			else
				std::cout << "President " << this->getTarget() << " has been pardoned by Zafod Beeblebrox" << std::endl;
		}
		else
			std::cout << "Form not signed" << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

bool PresidentialPardonForm::test = false;