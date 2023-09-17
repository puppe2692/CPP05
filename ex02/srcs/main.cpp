/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwyseur <nwyseur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:43:45 by nwyseur           #+#    #+#             */
/*   Updated: 2023/09/17 14:43:32 by nwyseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp" 
#include "../includes/Form.hpp"

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

///////////////////////////////////////////////////////////////////////////////

void basicTestF(void)
{
	std::cout << "----Basic Test Form ----" << std::endl;
	Form form("Red", 10, 9);
	Bureaucrat bureaucrat("Ricky Cleg", 8);
	std::cout << form << std::endl;
	bureaucrat.signedForm(form);
	std::cout << form << std::endl;
}

void tooLowCreaF(void)
{
	std::cout << "----Low signed Test form----" << std::endl;
	Form form("Yellow", 0, 10);
}

void tooHighCreaF(void)
{
	std::cout << "----high exec Test form----" << std::endl;
	Form form("Yellow", 10, 151);
}

void tooLowCreaE(void)
{
	std::cout << "----Low exec Test form----" << std::endl;
	Form form("Yellow", 10, 0);
}

void tooHighCreaE(void)
{
	std::cout << "----high exec Test form----" << std::endl;
	Form form("Yellow", 151, 10);
}

void signedTestF(void)
{
	std::cout << "----signed Test Form ----" << std::endl;
	Form form("Green", 10, 9);
	Bureaucrat bureaucrat("Ricky Gervais", 11);
	std::cout << form << std::endl;
	bureaucrat.signedForm(form);
	std::cout << form << std::endl;
}

int main(void)
{

	std::cout << "---- Test Bureaucrat ----" << std::endl;
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

	std::cout << "---- Test Form ----" << std::endl;
	
	try
	{
		basicTestF();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		tooLowCreaF();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		tooHighCreaF();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
		try
	{
		tooLowCreaE();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		tooHighCreaE();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		signedTestF();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

}