/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoskine <akoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 19:53:52 by akoskine          #+#    #+#             */
/*   Updated: 2024/05/29 19:14:55 by akoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

AForm::AForm() :
	_name("StandardForm"),
	_isSigned(false),
	_requiredToSign(150),
	_requiredToExecute(150)
{
	std::cout << CYAN "Form default constructor called." RESET << std::endl;
}

AForm::AForm(AForm const &src) :	
	_name(src._name),
	_isSigned(src._isSigned),
	_requiredToSign(src._requiredToSign),
	_requiredToExecute(src._requiredToExecute)
{
	std::cout << CYAN "Form copy constructor called." RESET << std::endl;
}

AForm::AForm(std::string const &name, int const requiredToSign, int const requiredToExecute) :
	_name(name),
	_isSigned(false),
	_requiredToSign(requiredToSign),
	_requiredToExecute(requiredToExecute)
{
	std::cout << CYAN "Form attributes constructor called." RESET << std::endl;
	if (requiredToSign < 1 || requiredToExecute < 1)
		throw AForm::GradeTooHighException();
	if (requiredToSign > 150 || requiredToExecute > 150)
		throw AForm::GradeTooLowException();
}

AForm::~AForm()
{
	std::cout << CYAN "Form destructor called." RESET << std::endl;
}

AForm &AForm::operator=(AForm const &src)
{
	std::cout << CYAN "Form assignment operator overload called." RESET << std::endl;
	this->_isSigned = src._isSigned;
	return (*this);
}

std::string const &AForm::getName() const
{
	return (this->_name);
}

bool	AForm::getSigned() const
{
	return (this->_isSigned);
}

int	AForm::getRequiredToSign(void) const
{
	return (this->_requiredToSign);
}

int	AForm::getRequiredToExecute(void) const
{
	return (this->_requiredToExecute);
}

void	AForm::beSigned(Bureaucrat const &bureaucrat)
{
	if (this->_isSigned)
		throw AForm::IsSignedException();
	if (bureaucrat.getGrade() > this->_requiredToSign)
		throw AForm::GradeTooLowException();
	this->_isSigned = true;
}

void	AForm::execute(Bureaucrat const &executor) const
{
	if (!this->_isSigned)
		throw NotSignedException();
	if (executor.getGrade() > this->_requiredToExecute)
		throw AForm::GradeTooLowException();
	this->doExecute();
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("Grade is too high.");	
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Grade is too low.");
}

const char *AForm::IsSignedException::what(void) const throw()
{
	return ("Form signed already.");
}

const char *AForm::NotSignedException::what(void) const throw()
{
	return ("Form hasn't been signed.");
}

std::ostream &operator<<(std::ostream &os, AForm const &obj)
{
	os	<< obj.getName() << " [Signed: " << (obj.getSigned() ? "Yes | " : "No | ")
		<< "Required to sign/execute: " << obj.getRequiredToSign() << "/" << obj.getRequiredToExecute() << "]";
	return (os);
}