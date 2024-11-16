/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoskine <akoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 19:32:32 by akoskine          #+#    #+#             */
/*   Updated: 2024/05/29 17:58:43 by akoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>
# include <fstream>
# include <cstdlib>
# include "Bureaucrat.hpp"

#define RESET	"\e[0m"
#define RED		"\e[31m"
#define GREEN	"\e[32m"
#define YELLOW	"\e[33m"
#define BLUE	"\e[34m"
#define PURPLE	"\e[35m"
#define CYAN	"\e[36m"

class Bureaucrat;

class AForm
{
	public:
		AForm();
		AForm(AForm const &src);
		AForm(std::string const &name, int const requiredToSign, int const requiredToExecute);
		virtual ~AForm();

		AForm &operator=(AForm const &src);

		std::string const &getName() const;
		bool getSigned() const;
		int getRequiredToSign() const;
		int getRequiredToExecute() const;

		void beSigned(Bureaucrat const &bureaucrat);
		void execute(Bureaucrat const &executor) const;

		class GradeTooHighException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
		class IsSignedException : public std::exception {
			public:
				virtual const char *	what(void) const throw();
		};
		class NotSignedException : public std::exception {
			public:
				virtual const char *	what(void) const throw();
		};

	protected:
		virtual void doExecute() const = 0;

	private:
		std::string const	_name;
		bool				_isSigned;
		int const			_requiredToSign;
		int const			_requiredToExecute;
};

std::ostream &operator<<(std::ostream &os, AForm const &obj);

#endif