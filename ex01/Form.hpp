/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytomiyos <ytomiyos@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 14:23:50 by ytomiyos          #+#    #+#             */
/*   Updated: 2021/11/18 17:38:06 by ytomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <exception>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string _name;
		bool _signed;
		const int _grade_sign;
		const int _grade_exec;
		Form(void);
	public:
		Form(const std::string &name, int grade_sign, int grade_exec);
		Form(Form const &copy);
		~Form(void);
		Form &operator=(const Form &copy);
		std::string getName(void) const;
		bool getSigned(void) const;
		int getGradeSign(void) const;
		int getGradeExec(void) const;
		void beSigned(Bureaucrat &bureaucrat);
		static bool test;
	public:
		class GradeTooHighException : public std::exception
		{
			virtual const char* what() const throw()
				{
					return "Grade Too High Exception";
				};
		};
		class GradeTooLowException : public std::exception
		{
			virtual const char* what() const throw()
				{
					return "Grade Too Low Exception";
				};
		};
};

std::ostream &operator<<(std::ostream &ostream, const Form &form);

#endif
