/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoskine <akoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 19:53:52 by akoskine          #+#    #+#             */
/*   Updated: 2024/05/29 11:30:58 by akoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Form::Form() :
	_name("StandardForm"),
	_isSigned(false),
	_requiredToSign(150),
	_requiredToExecute(150)
{
	std::cout << CYAN "Form default constructor called." RESET << std::endl;
}

Form::Form(Form const &src) :	
	_name(src._name),
	_isSigned(src._isSigned),
	_requiredToSign(src._requiredToSign),
	_requiredToExecute(src._requiredToExecute)
{
	std::cout << CYAN "Form copy constructor called." RESET << std::endl;
}

Form::Form(std::string const &name, int const requiredToSign, int const requiredToExecute) :
	_name(name),
	_isSigned(false),
	_requiredToSign(requiredToSign),
	_requiredToExecute(requiredToExecute)
{
	std::cout << CYAN "Form attributes constructor called." RESET << std::endl;
	if (requiredToSign < 1 || requiredToExecute < 1)
		throw Form::GradeTooHighException();
	if (requiredToSign > 150 || requiredToExecute > 150)
		throw Form::GradeTooLowException();
}

Form::~Form()
{
	std::cout << CYAN "Form destructor called." RESET << std::endl;
}

Form &Form::operator=(Form const &src)
{
	std::cout << CYAN "Form assignment operator overload called." RESET << std::endl;
	this->_isSigned = src._isSigned;
	return (*this);
}

std::string const &Form::getName() const
{
	return (this->_name);
}

bool	Form::getSigned() const
{
	return (this->_isSigned);
}

int	Form::getRequiredToSign(void) const
{
	return (this->_requiredToSign);
}

int	Form::getRequiredToExecute(void) const
{
	return (this->_requiredToExecute);
}

void	Form::beSigned(Bureaucrat const &bureaucrat)
{
	if (this->_isSigned)
		throw Form::IsSignedException();
	if (bureaucrat.getGrade() > this->_requiredToSign)
		throw Form::GradeTooLowException();
	this->_isSigned = true;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Grade is too high.");	
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too low.");
}

const char *Form::IsSignedException::what(void) const throw()
{
	return ("Form signed already.");
}

std::ostream &	operator<<(std::ostream &os, Form const &obj)
{
	os	<< "Form " << obj.getName() << " [Signed: " << (obj.getSigned() ? "Yes | " : "No | ")
		<< "Required to sign/execute: " << obj.getRequiredToSign() << "/" << obj.getRequiredToExecute() << "]";
	return (os);
}