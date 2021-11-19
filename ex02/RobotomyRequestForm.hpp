/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytomiyos <ytomiyos@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 17:52:15 by ytomiyos          #+#    #+#             */
/*   Updated: 2021/11/19 20:17:41 by ytomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include <string>
#include "Form.hpp"

class RobotomyRequestForm : public Form
{
	private:
		std::string _target;
	public:
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(RobotomyRequestForm const &copy);
		~RobotomyRequestForm(void);
		RobotomyRequestForm &operator=(RobotomyRequestForm const &copy);
		std::string getTarget(void) const;
		void execute(Bureaucrat const &executor) const;
		static bool test;
};

#endif
