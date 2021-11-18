/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytomiyos <ytomiyos@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 10:43:19 by ytomiyos          #+#    #+#             */
/*   Updated: 2021/11/18 14:08:03 by ytomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <exception>

class Bureaucrat
{
	private:
		const std::string _name;
		int _grade;
		Bureaucrat(void);
	public:
		Bureaucrat(const std::string &name, int grade);
		Bureaucrat(Bureaucrat const &copy);
		~Bureaucrat(void);
		Bureaucrat &operator=(Bureaucrat const &copy);
		std::string getName(void) const;
		int getGrade(void) const;
		void incrementGrade(void);
		void decrementGrade(void);
		static bool test;
	public:
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return "Grade is too high";
				};
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return "Grade is too low";
				};
		};
};

std::ostream &operator<<(std::ostream &ostream, Bureaucrat const &bureaucrat);

#endif
