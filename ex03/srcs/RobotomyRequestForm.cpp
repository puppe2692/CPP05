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

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const& other)
{
	std::cout << GREEN << "Robotomy copy constructor called" << RESET << std::endl;
	*this = other;
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

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (this->getBool() == false)
		throw (FormNotSignedExec());
	else if ( executor.getGrade() > this->getGradeToE())
		throw (GradeTooLowExceptionExec());
	else
	{
		std::cout << this->_target << " BZZZZZ Brrrrr BRRR BZzZ Briiit" << std::endl;
		std::srand(std::time(nullptr));
		int random_variable = std::rand();
		if (random_variable % 2 == 0)
			std::cout << this->_target << " robotomization is a complete success" << std::endl;
		else
			std::cout << this->_target << " robotomization is a failure" << std::endl;
	}
}