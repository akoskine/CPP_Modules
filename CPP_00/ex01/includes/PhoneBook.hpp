/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoskine <akoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 18:42:30 by akoskine          #+#    #+#             */
/*   Updated: 2024/01/08 22:25:40 by akoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <string>
# include "Contact.hpp"

class PhoneBook {
	private:
		int			_index;
		bool		_stop;
		Contact		_contacts[8];
		std::string	_getContactInfo(std::string const str);
		void		_printColumnNames(void);
		void		_printColumnContact(int const index);
		void		_printTrimmedContact(std::string str);
		bool 		_printIndexContact(std::string const input);
	public:
		PhoneBook();
		~PhoneBook();
		bool	addContact(void);
		bool	searchContact(void);
};

#endif