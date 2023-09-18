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

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const& other)
{
	std::cout << GREEN << "Presidential copy constructor called" << RESET << std::endl;
	*this = other;
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

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (this->getBool() == false)
		throw (FormNotSignedExec());
	else if ( executor.getGrade() > this->getGradeToE())
		throw (GradeTooLowExceptionExec());
	else
	{
		std::cout << this->_target << " a été pardonnée par Zaphod Beeblebrox." << std::endl;
	}
}