# include "../includes/Form.hpp"

Form::Form() : _name("Blue"), _gradeToSigned(150), _gradeToEx(150) , _isSigned(false)
{
	std::cout << GREEN << "Form default constructor called" << RESET << std::endl;
	return;
}

Form::Form(std::string name, int gradeToSigned, int gradeToEx) : _name(name), _gradeToSigned(gradeToSigned), _gradeToEx(gradeToEx), _isSigned(false)
{
	std::cout << GREEN << "Form parametric constructor called" << RESET << std::endl;
	if (gradeToSigned < 1 || gradeToEx < 1 )
		throw (GradeTooHighException());
	if (gradeToEx > 150 || gradeToSigned > 150)
		throw (GradeTooLowException());
	return;
}

Form::Form(Form const& other) : _name(other._name), _gradeToSigned(other._gradeToSigned), _gradeToEx(other._gradeToEx), _isSigned(other._isSigned)
{
	std::cout << GREEN << "Form copy constructor called" << RESET << std::endl;
	return;
}

Form& Form::operator=(Form const& other)
{
	if (this != &other)
		this->_isSigned = other.getBool();
	return (*this);
}

Form::~Form()
{
	std::cout << RED << "Form destructor called" << RESET << std::endl;
	return;
}

std::string const	Form::getName(void) const
{
	return (this->_name);
}

bool	Form::getBool(void) const
{
	return (this->_isSigned);
}

int const	Form::getGradeToS(void) const
{
	return (this->_gradeToSigned);
}

int const	Form::getGradeToE(void) const
{
	return (this->_gradeToEx);
}

void Form::beSigned(Bureaucrat const&  bureaucrat)
{
	if (bureaucrat.getGrade() <= this->getGradeToS())
		this->_isSigned = true;
	else
		throw (GradeTooLowException());
	return;
}

std::ostream& operator<<(std::ostream& o, Form const& other)
{
	o << "Form name: " << other.getName() << std::endl;
	o << other.getName() << " is signed: " << other.getBool() << std::endl;
	o << other.getName() << " grade to signed: " << other.getGradeToS() << std::endl;
	o << other.getName() << " grade to exec: " << other.getGradeToE() << std::endl;
	return (o);
}