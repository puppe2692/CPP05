/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwyseur <nwyseur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 14:22:03 by nwyseur           #+#    #+#             */
/*   Updated: 2023/09/15 14:47:35 by nwyseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("John")
{
	std::cout << GREEN << "Bureaucrat default constructor called" << RESET << std::endl;
	
	this->_grade = 150;
	return ;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	std::cout << GREEN << "Bureaucrat parameter constructor called" << RESET << std::endl;
	if (grade >= 150)
		throw (Bureaucrat::GradeTooLowException());
	if (grade <= 1)
		throw (Bureaucrat::GradeTooHighException());
	this->_grade = grade;
	return ;
}

Bureaucrat::Bureaucrat(Bureaucrat& other)
{
	*this = other;
	return;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << RED << "Bureaucrat destructor called" << RESET << std::endl;
	return;
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat& other)
{
	this->_grade = other.getGrade();
	return (*this);
}

std::string	Bureaucrat::getName(void) const
{
	return (this->_name);
}

int	Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

void	Bureaucrat::increaseGrade(void)
{
	if (this->_grade <= 1)
		throw (Bureaucrat::GradeTooHighException());
	else
		this->_grade--;
}

void	Bureaucrat::decreaseGrade(void)
{
	if (this->_grade >= 150)
		throw (Bureaucrat::GradeTooLowException());
	else
		this->_grade++;
}

std::ostream& operator<<(std::ostream& o, Bureaucrat const& other)
{
	o << other.getName() << " Bureaucrat, grade " << other.getGrade();
	return (o);
}