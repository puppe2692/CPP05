# include "../includes/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential", 25, 5), _target("Marc-Emmanuel")
{
	std::cout << GREEN << "Presidential default constructor called" << RESET << std::endl;
	return;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("Presidential", 25, 5), _target(target)
{
	std::cout << GREEN << "Presidential parametric constructor called" << RESET << std::endl;
	return;
}

PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential", 25, 5)
{
	std::cout << GREEN << "Presidential copy constructor called" << RESET << std::endl;
	return;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm const& other)
{
	if (this != &other)
		this->_target = other._target; // pourquoi getTarget ne marche pas?
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << RED << "Presidential destructor called" << RESET << std::endl;
	return;
}

std::string PresidentialPardonForm::getTarget()
{
	return(this->_target);
}