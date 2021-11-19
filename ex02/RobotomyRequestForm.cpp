/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytomiyos <ytomiyos@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 17:52:11 by ytomiyos          #+#    #+#             */
/*   Updated: 2021/11/19 20:55:18 by ytomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>  
#include "Form.hpp"
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) :
 Form("RobotomyRequestForm", 72, 45), _target(target)
{
	if (this->test)
		std::cout << "RobotomyRequestForm Constractor Called(" << this->getName() << ")" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &copy) :
 Form("RobotomyRequestForm", 72, 45)
{
	if (this->test)
		std::cout << "RobotomyRequestForm Copy Constractor Called(" << this->getName() << ")" << std::endl;
	*this = copy;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	if (this->test)
		std::cout << "RobotomyRequestForm Destractor Called(" << this->getName() << ")" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &copy)
{
	if (this->test)
		std::cout << "RobotomyRequestForm Copy Assign Called(" << copy.getName() << ")" << std::endl;
	return (*this);
}

std::string RobotomyRequestForm::getTarget(void) const
{
	return (this->_target);
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (this->test)
		std::cout << "RobotomyRequestForm Execute Called(" << this->getName() << ")" << std::endl;
	std::srand(time(NULL));
	try {
		if (this->getSigned())
		{
			if (executor.getGrade() <= this->getGradeExec())
			{
				std::cout << "rizzz...(drill)" << std::endl;
				if (std::rand() % 2)
					std::cout << this->getTarget() << " has been robotomized successfully" << std::endl;
				else
					std::cout << this->getTarget() << " has been robotomized failed" << std::endl;
			}
			else
				throw Form::GradeTooLowException();
		}
		else
			std::cout << "Form not signed" << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

bool RobotomyRequestForm::test = false;
