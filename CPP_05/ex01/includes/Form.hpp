/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoskine <akoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 19:32:32 by akoskine          #+#    #+#             */
/*   Updated: 2024/05/29 13:37:13 by akoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

#define RESET	"\e[0m"
#define RED		"\e[31m"
#define GREEN	"\e[32m"
#define YELLOW	"\e[33m"
#define BLUE	"\e[34m"
#define PURPLE	"\e[35m"
#define CYAN	"\e[36m"

class Bureaucrat;

class Form
{
	public:
		Form();
		Form(Form const &src);
		Form(std::string const &name, int const requiredToSign, int const requiredToExecute);
		~Form();

		Form &operator=(Form const &src);

		std::string const &getName() const;
		bool getSigned() const;
		int getRequiredToSign() const;
		int getRequiredToExecute() const;

		void beSigned(Bureaucrat const &bureaucrat);

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

	private:
		std::string const	_name;
		bool				_isSigned;
		int const			_requiredToSign;
		int const			_requiredToExecute;
};

std::ostream &operator<<(std::ostream &os, Form const &obj);

#endif