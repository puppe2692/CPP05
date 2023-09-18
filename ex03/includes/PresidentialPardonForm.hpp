#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"
# include "AForm.hpp"

# define RED "\e[0;31m"
# define RESET "\e[0m"
# define GREEN "\e[0;32m"
# define YELLOW "\e[0;33m"

class Bureaucrat;

class PresidentialPardonForm : public AForm
{
	public :
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(PresidentialPardonForm const& other);
		~PresidentialPardonForm();
		PresidentialPardonForm& operator=(PresidentialPardonForm const& other);

		std::string getTarget();

		void execute(Bureaucrat const & executor) const;

	private :
		std::string _target;
	
	class GradeTooLowExceptionExec : public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return ("Presidential::exception : Grade is too Low to exec");
			}
	};

	class FormNotSignedExec : public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return ("Presidential::exception : Form is not signed");
			}
	};
};


#endif