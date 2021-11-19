/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytomiyos <ytomiyos@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 10:43:14 by ytomiyos          #+#    #+#             */
/*   Updated: 2021/11/18 17:43:26 by ytomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <exception>
#include <string>
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name(""), _grade(150)
{
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name), _grade(grade)
{
	if (this->test)	
		std::cout << "Bureaucrat Constractor Called(" << name << ")" << std::endl;
	try {
		if (grade < 1)
			throw GradeTooHighException();
		if (grade > 150)
			throw GradeTooLowException();
	} catch (std::exception const &e) {
		std::cout << e.what() << std::endl;
	}
}

Bureaucrat::Bureaucrat(Bureaucrat const &copy)
{
	if (this->test)	
		std::cout << "Bureaucrat Copy Constractor Called" << std::endl;
	*this = copy;
}

Bureaucrat::~Bureaucrat(void)
{
	if (this->test)	
		std::cout << "Bureaucrat Destructor Called(" << _name << ")" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &copy)
{
	if (this->test)	
		std::cout << "Bureaucrat Copy Assign Called" << std::endl;
	_grade = copy._grade;
	return (*this);
}

std::string Bureaucrat::getName(void) const
{
	return (this->_name);
}

int Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

void Bureaucrat::incrementGrade(void)
{
	if (this->test)	
		std::cout << "IncrementGrade Called(" << _name << ")" << std::endl;
	try {
		if (this->_grade - 1 < 1)
			throw Bureaucrat::GradeTooHighException();
		this->_grade--;
	} catch (std::exception const &e) {
		std::cout << e.what() << std::endl;
	}
}

void Bureaucrat::decrementGrade(void)
{
	if (this->test)
		std::cout << "DecrementGrade Called(" << _name << ")" << std::endl;
	try {
		if (this->_grade + 1 > 150)
			throw Bureaucrat::GradeTooLowException();
		this->_grade++;
	} catch (std::exception const &e) {
		std::cout << e.what() << std::endl;
	}
}

void Bureaucrat::signForm(Form &form)
{
	if (this->test)
		std::cout << "SignForm Called(" << _name << ")" << std::endl;
	try {
		if (this->_grade > form.getGradeSign())
			throw Bureaucrat::GradeTooLowException();
		form.beSigned(*this);
	} catch (std::exception const &e) {
		std::cout << e.what() << std::endl;
	}
}

std::ostream &operator<<(std::ostream &ostream, Bureaucrat const &bureaucrat)
{
	ostream << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return (ostream);
}

bool Bureaucrat::test = false;
