/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytomiyos <ytomiyos@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 10:43:11 by ytomiyos          #+#    #+#             */
/*   Updated: 2021/11/18 14:20:29 by ytomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"

int main()
{
	// Bureaucrat::test = true;

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

	return (0);
}