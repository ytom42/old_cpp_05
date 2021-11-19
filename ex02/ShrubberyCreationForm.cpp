/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytomiyos <ytomiyos@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 17:52:09 by ytomiyos          #+#    #+#             */
/*   Updated: 2021/11/19 20:55:03 by ytomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) :
 Form("ShrubberyCreationForm", 145, 137), _target(target)
{
	if (this->test)
		std::cout << "ShrubberyCreation Constructor Called(" << this->getName() << ")" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &copy) :
 Form("ShrubberyCreationForm", 145, 137)
{
	if (this->test)
		std::cout << "ShrubberyCreation Copy Constructor Called(" << copy.getName() << ")" << std::endl;
	*this = copy;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	if (this->test)
		std::cout << "ShrubberyCreation Destructor Called(" << this->getName() << ")" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &copy)
{
	if (this->test)
		std::cout << "ShrubberyCreation Copy Assignment Called(" << copy.getName() << ")" << std::endl;
	return (*this);
}

std::string ShrubberyCreationForm::getTarget(void) const
{
	return (this->_target);
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (this->test)
		std::cout << "ShrubberyCreationForm::execute Called(" << this->getName() << ")" << std::endl;
	try {
		if (this->getGradeExec() < executor.getGrade())
			throw Form::GradeTooLowException();
		else if (this->getGradeExec() >= executor.getGrade() && this->getSigned() == true)
		{
			std::ofstream file(this->_target + "_shrubbery");
			file << "       _-_" << std::endl;
			file << "    /~~   ~~\\ " << std::endl;
			file << " /~~         ~~\\ " << std::endl;
			file << "{               }" << std::endl;
			file << " \\  _-     -_  /" << std::endl;
			file << "   ~  \\   /  ~" << std::endl;
			file << "       | |" << std::endl;
			file << "       | |" << std::endl;
			file << "      /   \\ " << std::endl;
			file << "------------------" << std::endl;
			std::cout << "Creating a Shrubbery for " << this->getTarget() << std::endl;
		}
		else
			std::cout << "Form not signed" << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

bool ShrubberyCreationForm::test = false;
