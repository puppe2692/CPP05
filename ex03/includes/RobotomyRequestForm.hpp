#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"
# include "AForm.hpp"

# define RED "\e[0;31m"
# define RESET "\e[0m"
# define GREEN "\e[0;32m"
# define YELLOW "\e[0;33m"

class Bureaucrat;

class RobotomyRequestForm : public AForm
{
	public :
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(RobotomyRequestForm const& other);
		~RobotomyRequestForm();
		RobotomyRequestForm& operator=(RobotomyRequestForm const& other);

		std::string getTarget();

		void execute(Bureaucrat const & executor) const;

		class GradeTooLowExceptionExec : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Robotomy::exception : Grade is too Low to exec");
				}
		};

		class FormNotSignedExec : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Robotomy::exception : Form is not signed");
				}
		};

	private :
		std::string _target;
};


#endif