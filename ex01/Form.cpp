/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytomiyos <ytomiyos@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 14:23:41 by ytomiyos          #+#    #+#             */
/*   Updated: 2021/11/18 17:27:36 by ytomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <exception>
#include <string>
#include "Form.hpp"

Form::Form(void) : _name(""), _signed(false), _grade_sign(150), _grade_exec(150)
{
}

Form::Form(std::string const &name, int grade_sign, int grade_exec) : _name(name), _grade_sign(grade_sign), _grade_exec(grade_exec)
{
	if (this->test)
		std::cout << "Form Constractor Called(" << name << ")" << std::endl;
	try {
		if (grade_sign < 1 || grade_exec < 1)
			throw GradeTooHighException();
		if (grade_sign > 150 || grade_exec > 150)
			throw GradeTooLowException();
	} catch (std::exception const &e) {
		std::cout << e.what() << std::endl;
	}
}

Form::Form(Form const &copy) : _name(copy._name), _signed(copy._signed), _grade_sign(copy._grade_sign), _grade_exec(copy._grade_exec)
{
	if (this->test)
		std::cout << "Form Constractor Called(" << copy._name << ")" << std::endl;
}

Form::~Form(void)
{
	if (this->test)
		std::cout << "Form Destractor Called(" << this->_name << ")" << std::endl;
}

Form &Form::operator=(Form const &copy)
{
	if (this->test)
		std::cout << "Form operator= Called(" << copy._name << ")" << std::endl;
	this->_signed = copy.getSigned();
	return *this;
}

std::string Form::getName(void) const
{
	return (this->_name);
}

bool Form::getSigned(void) const
{
	return (this->_signed);
}

int Form::getGradeSign(void) const
{
	return (this->_grade_sign);
}

int Form::getGradeExec(void) const
{
	return (this->_grade_exec);
}

void Form::beSigned(Bureaucrat &bureaucrat)
{
	try {
		if (bureaucrat.getGrade() > this->_grade_sign)
			throw GradeTooLowException();
		this->_signed = true;
		if (this->test)
			std::cout << "Form Signed by " << bureaucrat.getName() << std::endl;
	} catch (std::exception const &e) {
		std::cout << e.what() << std::endl;
	}
}

std::ostream &operator<<(std::ostream &ostream, Form const &form)
{
	ostream << form.getName() << ", ";
	if (form.getSigned())
		ostream << "signed";
	else
		ostream << "not signed";
	ostream << ", grade to sign " << form.getGradeSign() << ", grade to execute " << form.getGradeExec();
	return (ostream);
}

bool Form::test = false;
