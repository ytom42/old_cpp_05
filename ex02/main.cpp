/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytomiyos <ytomiyos@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 10:43:11 by ytomiyos          #+#    #+#             */
/*   Updated: 2021/11/19 20:57:28 by ytomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void ex00_test(void)
{
	Bureaucrat b1("b1", 43);
	std::cout << b1 << std::endl;
	b1.incrementGrade();
	std::cout << b1 << std::endl;
	b1.decrementGrade();
	std::cout << b1 << std::endl << std::endl;

	Bureaucrat b2("b2", 1);
	std::cout << b2 << std::endl;
	b2.incrementGrade();
	std::cout << b2 << std::endl << std::endl;

	Bureaucrat b3("b3", 150);
	std::cout << b3 << std::endl;
	b3.decrementGrade();
	std::cout << b3 << std::endl << std::endl;

	Bureaucrat b4("b4", -1);
	Bureaucrat b5("b5", 151);
}

void ex01_test(void)
{
	Bureaucrat b1("b1", 43);
	Bureaucrat b2("b2", 1);
	Bureaucrat b3("b3", 150);

	Form f1("f1", 42, 42);
	std::cout << f1 << std::endl;
	f1.beSigned(b1);
	std::cout << f1 << std::endl << std::endl;

	Form f2("f2", 1, 1);
	std::cout << f2 << std::endl;
	f2.beSigned(b2);
	std::cout << f2 << std::endl << std::endl;

	Form f3("f3", 150, 150);
	std::cout << f3 << std::endl;
	f3.beSigned(b3);
	std::cout << f3 << std::endl << std::endl;

	b2.signForm(f1);
	std::cout << f1 << std::endl << std::endl;

	Form f4("f4", -1, -1);
	Form f5("f5", 151, 151);
}

void ex02_test()
{
	Bureaucrat b1("b1", 1);
	Bureaucrat b2("b2", 150);
	Bureaucrat b3("b3", 20);

	ShrubberyCreationForm s1("s1");
	s1.execute(b1);
	std::cout << s1 << std::endl;
	s1.beSigned(b1);
	std::cout << s1 << std::endl;
	s1.execute(b2);
	s1.execute(b1);
	std::cout << std::endl;

	RobotomyRequestForm r1("r1");
	s1.execute(b1);
	std::cout << r1 << std::endl;
	r1.beSigned(b1);
	std::cout << r1 << std::endl;
	r1.execute(b2);
	r1.execute(b1);
	std::cout << std::endl;

	PresidentialPardonForm p1("p1");
	s1.execute(b1);
	std::cout << p1 << std::endl;
	p1.beSigned(b3);
	std::cout << p1 << std::endl;
	p1.execute(b3);
	p1.execute(b1);
	std::cout << std::endl;
}

int main()
{
	// Bureaucrat::test = true;
	// Form::test = true;
	// ShrubberyCreationForm::test = true;
	// RobotomyRequestForm::test = true;

	// ex00_test();
	// ex01_test();
	ex02_test();

	return (0);
}