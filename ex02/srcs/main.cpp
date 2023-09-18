/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwyseur <nwyseur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:43:45 by nwyseur           #+#    #+#             */
/*   Updated: 2023/09/18 14:43:47 by nwyseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include <iomanip>

int	main(void)
{
	srand(time(NULL));

	std::cout << "----Shrubbery Creation----" << std::endl;
	AForm		*shrub = new ShrubberyCreationForm("home");
	Bureaucrat	corr("Correcteur", 1);
	Bureaucrat	me("Kevin", 140);

	corr.executeForm(*shrub);
	corr.signForm(*shrub);
	std::cout << *shrub << std::endl;
	std::cout << corr << std::endl;
	corr.executeForm(*shrub);
	me.executeForm(*shrub);
	delete shrub;


	std::cout << "----Robotomy Request----" << std::endl;
	AForm		*robotomy = new RobotomyRequestForm("Correcteur");
	Bureaucrat	me2("Herve", 1);

	me2.executeForm(*robotomy);
	me2.signForm(*robotomy);
	me2.executeForm(*robotomy);
	
	me2.executeForm(*robotomy);
	me2.executeForm(*robotomy);
	me2.executeForm(*robotomy);
	delete robotomy;
	
	std::cout << "----Presidential Pardon----" << std::endl;
	AForm		*presidential = new PresidentialPardonForm("Correcteur");
	Bureaucrat	me3("Rayan", 6);

	me3.executeForm(*presidential);
	me3.signForm(*presidential);
	me3.executeForm(*presidential);
	me3.increaseGrade();
	me3.executeForm(*presidential);
	delete presidential;

	return (0);
}