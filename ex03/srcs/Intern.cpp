/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwyseur <nwyseur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 15:11:36 by nwyseur           #+#    #+#             */
/*   Updated: 2023/09/18 16:31:05 by nwyseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Intern.hpp"

Intern::Intern()
{
	std::cout << GREEN << "Intern default constructor called" << RESET << std::endl;
	return;
}

Intern::Intern(Intern const& other)
{
	std::cout << GREEN << "Intern copy constructor called" << RESET << std::endl;
	*this = other;
	return;
}

Intern::~Intern()
{
	std::cout << RED << "Intern destructor called" << RESET << std::endl;
	return;
}

Intern& Intern::operator=(Intern const& other)
{
	(void)other;
	return (*this);
}

static AForm	*newShrubbery(const std::string target)
{
	return (new ShrubberyCreationForm(target));
}

static AForm	*newRobotomy(const std::string target)
{
	return (new RobotomyRequestForm(target));
}

static AForm	*newPresidential(const std::string target)
{
	return (new PresidentialPardonForm(target));
}

int getIndex(std::string formName)
{
	int i = 0;
	std::string formArray[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	while (i != 3)
	{
		if (formArray[i] == formName)	
			return (i);
		i++;
	}
	return (i);
}

AForm* Intern::makeForm(std::string formName, std::string target) const
{
	AForm* (*functionArray[3])(std::string const) = {newShrubbery, newRobotomy, newPresidential};
	int i = getIndex(formName);
	if (i > 2)
		std::cout << "Intern unable to create form : unexisting form name request" << std::endl;
	else
	{
		std::cout << "Intern creates " << formName << std::endl;
		return (functionArray[i](target));
	}
	return (NULL);
}