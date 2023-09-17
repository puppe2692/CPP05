/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwyseur <nwyseur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 14:44:29 by nwyseur           #+#    #+#             */
/*   Updated: 2023/09/17 14:36:07 by nwyseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>
#include <fstream>
# include "Bureaucrat.hpp"

# define RED "\e[0;31m"
# define RESET "\e[0m"
# define GREEN "\e[0;32m"
# define YELLOW "\e[0;33m"

class Bureaucrat;

class AForm
{
	public :
		AForm();
		AForm(AForm const& other);
		AForm(std::string name, int gradeToSigned, int gradeToEx);
		virtual ~AForm();
		AForm& operator=(AForm const& other);

		std::string const	getName(void) const;
		bool		getBool(void) const;
		int	getGradeToS(void) const;
		int	getGradeToE(void) const;

		void beSigned(Bureaucrat const& bureaucrat);
		virtual void execute(Bureaucrat const & executor) const = 0;

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("AForm::exception : Grade is too high");
				}

		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("AForm::exception : Grade is too Low");
				}
		};
		class GradeTooLowExceptionSign : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Aform::exception : Grade is too Low to sign");
				}
		};



	private :
		std::string const _name;
		bool _isSigned;
		int const _gradeToSigned;
		int const _gradeToEx;
};

std::ostream& operator<<(std::ostream& o, AForm const& other);

#endif