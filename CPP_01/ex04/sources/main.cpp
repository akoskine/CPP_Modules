/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoskine <akoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 18:38:03 by akoskine          #+#    #+#             */
/*   Updated: 2024/01/12 20:12:04 by akoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

std::string	ownReplace(std::string str, std::string s1, std::string s2) {
	std::string	temp;
	int	len = s1.length();
	for (int i = 0; str[i]; i++) {
		if (!std::strncmp(&str.c_str()[i], s1.c_str(), len)) {
			temp.append(s2);
			i += len - 1;
		}
		else
			temp.push_back(str.c_str()[i]);
	}
	return (temp);
}

int	main(int ac, char **av) {
	if (ac != 4)
	{
		std::cout << "Wrong amount of arguments" << std::endl
			<< "Correct syntax is ./replace <filename> <str to replace> <replace with str>" << std::endl;
		return (0);
	}
	std::string	filename = av[1];
	std::ifstream	infile(filename.c_str());
	if (!infile) {
		std::perror("Original file failed to open");
		return (-1);
	}
	std::ofstream	outfile((filename + ".replace").c_str());
	if (!outfile) {
		infile.close();
		std::perror("New file failed to open");
		return (-1);
	}
	std::string	str;
	while(std::getline(infile, str) && !infile.bad() && !infile.eof()) {
		str = ownReplace(str, av[2], av[3]);
		outfile << str << std::endl;
	}
		if (outfile.bad())
		{
			infile.close();
			outfile.close();
			std::perror("New file corrupted");
			return (-1);
		}
	if (infile.bad())
	{
		infile.close();
		outfile.close();
		std::perror("Original file corrupted");
		return (-1);
	}
	infile.close();
	outfile.close();
	str.clear();
	return (0);
}