# include "../includes/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery", 145, 137), _target("Jean-Louis")
{
	std::cout << GREEN << "Shrubbery default constructor called" << RESET << std::endl;
	return;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shrubbery", 145, 137), _target(target)
{
	std::cout << GREEN << "Shrubbery parametric constructor called" << RESET << std::endl;
	return;
}

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery", 145, 137)
{
	std::cout << GREEN << "Shrubbery copy constructor called" << RESET << std::endl;
	return;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm const& other)
{
	if (this != &other)
		this->_target = other._target; // pourquoi getTarget ne marche pas?
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << RED << "Shrubbery destructor called" << RESET << std::endl;
	return;
}

std::string ShrubberyCreationForm::getTarget()
{
	return(this->_target);
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	std::ofstream	outfile;
	std::string		filename;

	if ( executor.getGrade() < this->getGradeToE())
		throw (GradeTooLowExceptionExec());
	else
	{
		filename = this->_target + "_shrubbery";
		outfile.open(filename);
		if (!outfile.is_open())
		{
			std::cout << "Unable to open outfile" << std::endl;
			throw ("Error outfile opening");
		}
		else
		{
			outfile << "             ,@@@@@@@,            "    << std::endl;
			outfile << "     ,,,.   ,@@@@@@/@@,  .oo8888o."    << std::endl;
			outfile << "  ,&%%&%&&%,@@@@@/@@@@@@,888\\88//8o"    << std::endl;
			outfile << " ,%&\\%&%&&%,@@\\@@@//@@@88\\8888//888'"    << std::endl;
			outfile << " %&&%&%&/%&&%@@\\@/ //@@@8888\\8888888'"    << std::endl;
			outfile << " %&&%/ %&%%&&@@\\V /@@' `88\\8 `//88'"    << std::endl;
			outfile << " `&%\\ ` /%&'    |.|        8\\'|8'"    << std::endl;
			outfile << "      |o|        | |         | |    "        << std::endl;
			outfile << "      |.|        | |         | |    "        << std::endl;
			outfile << "  \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_"    << std::endl;
		}
	}
}