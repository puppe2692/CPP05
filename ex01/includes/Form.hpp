/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwyseur <nwyseur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 14:44:29 by nwyseur           #+#    #+#             */
/*   Updated: 2023/09/15 16:13:54 by nwyseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

# define RED "\e[0;31m"
# define RESET "\e[0m"
# define GREEN "\e[0;32m"
# define YELLOW "\e[0;33m"

class Form
{
	public :
		Form();
		Form(Form const& other);
		Form(std::string name, int gradeToSigned, int gradeToEx);
		~Form();
		Form& operator=(Form const& other);

		std::string const	getName(void) const;
		bool		getBool(void) const;
		int const	getGradeToS(void) const;
		int const	getGradeToE(void) const;

		void beSigned(Bureaucrat const& bureaucrat);

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("Form::exception : Grade is too high");
				}

		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Form::exception : Grade is too Low");
				}
		};



	private :
		std::string const _name;
		bool _isSigned;
		int const _gradeToSigned;
		int const _gradeToEx;
};

std::ostream& operator<<(std::ostream& o, Form const& other);

#endif