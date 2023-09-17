# include "../includes/AForm.hpp"

AForm::AForm() : _name("Blue"), _isSigned(false), _gradeToSigned(150), _gradeToEx(150)
{
	std::cout << GREEN << "AForm default constructor called" << RESET << std::endl;
	return;
}

AForm::AForm(std::string name, int gradeToSigned, int gradeToEx) : _name(name), _isSigned(false), _gradeToSigned(gradeToSigned), _gradeToEx(gradeToEx)
{
	std::cout << GREEN << "AForm parametric constructor called" << RESET << std::endl;
	if (gradeToSigned < 1 || gradeToEx < 1 )
		throw (GradeTooHighException());
	if (gradeToEx > 150 || gradeToSigned > 150)
		throw (GradeTooLowException());
	return;
}

AForm::AForm(AForm const& other) : _name(other._name), _isSigned(other._isSigned), _gradeToSigned(other._gradeToSigned), _gradeToEx(other._gradeToEx)
{
	std::cout << GREEN << "AForm copy constructor called" << RESET << std::endl;
	return;
}

AForm& AForm::operator=(AForm const& other)
{
	if (this != &other)
		this->_isSigned = other.getBool();
	return (*this);
}

AForm::~AForm()
{
	std::cout << RED << "AForm destructor called" << RESET << std::endl;
	return;
}

std::string const	AForm::getName(void) const
{
	return (this->_name);
}

bool	AForm::getBool(void) const
{
	return (this->_isSigned);
}

int	AForm::getGradeToS(void) const
{
	return (this->_gradeToSigned);
}

int	AForm::getGradeToE(void) const
{
	return (this->_gradeToEx);
}

void AForm::beSigned(Bureaucrat const&  bureaucrat)
{
	if (bureaucrat.getGrade() <= this->getGradeToS())
		this->_isSigned = true;
	else
		throw (GradeTooLowExceptionSign());
	return;
}

std::ostream& operator<<(std::ostream& o, AForm const& other)
{
	o << "AForm name: " << other.getName() << std::endl;
	o << other.getName() << " is signed: " << other.getBool() << std::endl;
	o << other.getName() << " grade to signed: " << other.getGradeToS() << std::endl;
	o << other.getName() << " grade to exec: " << other.getGradeToE() << std::endl;
	return (o);
}