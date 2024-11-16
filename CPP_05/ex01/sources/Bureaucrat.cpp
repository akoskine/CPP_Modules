/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoskine <akoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 18:23:26 by akoskine          #+#    #+#             */
/*   Updated: 2024/05/29 19:19:31 by akoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat() : _name("NoName"), _grade(1)
{
	std::cout << CYAN << "Bureaucrat default constructor called." << RESET << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &src) : _name(src._name), _grade(src._grade)
{
	std::cout << CYAN << "Bureaucrat copy constructor called." << RESET << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name), _grade(grade)
{
	std::cout << CYAN << "Bureaucrat attributes constructor called." << RESET << std::endl;
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade = grade;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << CYAN << "Bureaucrat destructor called." << RESET << std::endl;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &src)
{
	std::cout << CYAN << "Bureaucrat assignment operator overload called." << RESET << std::endl;
	this->_grade = src._grade;
	return (*this);
}

std::string const &Bureaucrat::getName() const
{
	return (this->_name);
}

int	Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void	Bureaucrat::increment()
{
	std::cout << YELLOW << "Trying to increment grade." << RESET << std::endl;
	if (this->_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	else
	{
		std::cout << GREEN << "Bureaucrat's [" << *this << "] grade was increased to " << this->_grade - 1 << "." << RESET << std::endl;
		this->_grade -= 1;
	}
}

void	Bureaucrat::decrement()
{
	std::cout << YELLOW << "Trying to decrement grade." << RESET << std::endl;
	if (this->_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	else
	{
		std::cout << GREEN << "Bureaucrat's [" << *this << "] grade was decreased to " << this->_grade + 1 << "." << RESET << std::endl;
		this->_grade += 1;
	}
}

void	Bureaucrat::signForm(Form &form) const
{
	try
	{
		form.beSigned(*this);
		std::cout << GREEN << *this << " signed " << form << RESET << std::endl;
	}
	catch (std::exception const &e)
	{
		std::cout << RED << *this << " couldn't sign " << form << " because "
			<< e.what() << RESET << std::endl;
	}
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high.");	
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low.");
}

std::ostream &operator<<(std::ostream &os, Bureaucrat const &obj)
{
	os << obj.getName() << ", bureaucrat grade " << obj.getGrade() << ".";
	return (os);
}