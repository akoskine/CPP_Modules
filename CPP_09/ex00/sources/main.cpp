/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoskine <akoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 19:46:39 by akoskine          #+#    #+#             */
/*   Updated: 2024/08/15 21:33:55 by akoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int check_header(const std::string &line) {
    if (line != "date | value")
        throw std::runtime_error("Error: invalid header");
    return (1);
}

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        try
        {
            int header = 0;
            std::ifstream file(argv[1]);
            if (!file.is_open())
                std::cout << "Unable to open the file" << std::endl;
            if (file.peek() == '\n' || file.eof())
                std::cout << "The file is empty" << std::endl;
            std::string line;
            BitcoinExchange btcExchange;
            while (std::getline(file, line))
            {
                std::istringstream iss(line);
                std::string date;
                float value;
                char separator;

                if (!header)
                {
                    header = check_header(line);
                    continue ;
                }
                if (line == "")
                    continue ;
                iss >> date >> separator >> value;
                if (!btcExchange.isValidDate(date))
                    std::cout << "Error: bad input => " << date << std::endl;
                else if (value < 0)
                    std::cout << "Error: not a positive number." << std::endl;
                else if (value > 1000)
                    std::cout << "Error: too large a number." << std::endl;
                else
                    std::cout << date << " => " << value << " = " << (btcExchange.getExchangeRate(date) * value) << std::endl;
            }
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    else
        std::cerr << "Error: could not open file." << std::endl;
    return (0);
}
