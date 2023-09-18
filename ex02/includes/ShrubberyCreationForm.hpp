#ifndef SHREBBERYCREATIONFORM_HPP
# define SHREBBERYCREATIONFORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"
# include "AForm.hpp"

# define RED "\e[0;31m"
# define RESET "\e[0m"
# define GREEN "\e[0;32m"
# define YELLOW "\e[0;33m"

class Bureaucrat;

class ShrubberyCreationForm : public AForm
{
	public :
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(ShrubberyCreationForm const& other);
		~ShrubberyCreationForm();
		ShrubberyCreationForm& operator=(ShrubberyCreationForm const& other);

		std::string getTarget();

		void execute(Bureaucrat const & executor) const;

		class GradeTooLowExceptionExec : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Shrubbery::exception : Grade is too Low to exec");
				}
		};

	private :
		std::string _target;
};


#endif