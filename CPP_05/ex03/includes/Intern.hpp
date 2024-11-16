/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoskine <akoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 19:39:13 by akoskine          #+#    #+#             */
/*   Updated: 2024/05/29 19:47:46 by akoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{
	public:
		Intern();
		Intern(Intern const &src);
		~Intern();

		Intern &operator=(Intern const &src);

		AForm *makeForm(std::string name, std::string target);

		class WrongFormName : public std::exception {
			public:
				virtual const char *what() const throw();
		};
};

#endif