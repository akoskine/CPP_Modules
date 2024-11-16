/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoskine <akoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 04:00:56 by akoskine          #+#    #+#             */
/*   Updated: 2024/01/17 04:31:27 by akoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>

class Brain
{
	public:
		Brain();
		Brain(const Brain& src);
		~Brain();

		Brain &	operator=(const Brain& src);

		const std::string&	getIdea(int index) const;
		void				setIdea(int index, const std::string& idea);

		static int const	nbIdeas = 100;

	private:
		std::string	_ideas[nbIdeas];
};

#endif