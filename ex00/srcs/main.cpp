/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwyseur <nwyseur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:43:45 by nwyseur           #+#    #+#             */
/*   Updated: 2023/09/15 14:56:12 by nwyseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp" 

void basicTest(void)
{
	std::cout << "----Basic Test----" << std::endl;
	Bureaucrat Bureaucrat("Ricky", 10);
	std::cout << Bureaucrat << std::endl;
	Bureaucrat.decreaseGrade();
	std::cout << Bureaucrat << std::endl;
	Bureaucrat.increaseGrade();
	std::cout << Bureaucrat << std::endl;

}

void tooLowCrea(void)
{
	std::cout << "----Low Test Crea----" << std::endl;
	Bureaucrat Bureaucrat("Johnny", 0);
}

void tooLowInc(void)
{
	std::cout << "----Low Test----" << std::endl;
	Bureaucrat Bureaucrat("Johnny", 1);
}

void tooHighDec(void)
{
	std::cout << "----high Test----" << std::endl;
	Bureaucrat Bureaucrat("Johnny", 150);
	Bureaucrat.decreaseGrade();
}

void tooHighCrea(void)
{
	std::cout << "----high Test Crea----" << std::endl;
	Bureaucrat Bureaucrat("Johnny", 151);
}

int main(void)
{
	try
	{
		basicTest();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		tooLowCrea();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		tooLowInc();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		tooHighCrea();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		tooHighDec();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	
}