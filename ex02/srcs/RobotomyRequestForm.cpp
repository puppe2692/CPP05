# include "../includes/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy", 72, 45), _target("George-Alain")
{
	std::cout << GREEN << "Robotomy default constructor called" << RESET << std::endl;
	return;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robotomy", 72, 45), _target(target)
{
	std::cout << GREEN << "Robotomy parametric constructor called" << RESET << std::endl;
	return;
}

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy", 72, 45)
{
	std::cout << GREEN << "Robotomy copy constructor called" << RESET << std::endl;
	return;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm const& other)
{
	if (this != &other)
		this->_target = other._target; // pourquoi getTarget ne marche pas?
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << RED << "Robotomy destructor called" << RESET << std::endl;
	return;
}

std::string RobotomyRequestForm::getTarget()
{
	return(this->_target);
}