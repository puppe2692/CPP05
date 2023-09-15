/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwyseur <nwyseur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 12:27:42 by nwyseur           #+#    #+#             */
/*   Updated: 2023/09/15 14:45:42 by nwyseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>

# define RED "\e[0;31m"
# define RESET "\e[0m"
# define GREEN "\e[0;32m"
# define YELLOW "\e[0;33m"

class Bureaucrat
{
	public:
		Bureaucrat(void);
		Bureaucrat(std::string name, int grade);
		Bureaucrat(Bureaucrat& other);
		~Bureaucrat();
		
		Bureaucrat& operator=(Bureaucrat& other);

		std::string	getName(void) const;
		int			getGrade(void) const;

		void		increaseGrade(void);
		void		decreaseGrade(void);

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("Bureaucrat::exception : Grade is too high");
				}

		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Bureaucrat::exception : Grade is too Low");
				}
		};

	private:
		const std::string	_name;
		int					_grade;
};

std::ostream& operator<<(std::ostream& o, Bureaucrat const& other);

#endif