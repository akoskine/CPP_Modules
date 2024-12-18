/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoskine <akoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 19:47:01 by akoskine          #+#    #+#             */
/*   Updated: 2024/08/15 19:58:54 by akoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
    populateExchangeRates();
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &copy)
{
    *this = copy;
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &copy)
{
    if (this !=&copy)
        _exchangeRates = copy._exchangeRates;
    return (*this);
}

float BitcoinExchange::getExchangeRate(std::string date)
{
    std::map<std::string, float>::const_iterator it = _exchangeRates.lower_bound(date);
	if (it == _exchangeRates.end() || it->first != date)
	{
		if (it != _exchangeRates.begin())
		    --it;
	}
	return it->second;
}

void BitcoinExchange::populateExchangeRates()
{
    std::ifstream file("data.csv");
    if (!file.is_open())
        throw std::runtime_error("Error: unable to open file data.csv");
    
    std::string line;
    while (std::getline(file, line))
    {
        std::istringstream iss(line);
        std::string date, value;

        if (line == "date,exchange_rate" || line == "")
            continue ;
        if (!(std::getline(iss, date, ',') && std::getline(iss, value)))
            throw std::runtime_error("Error: invalid csv data format");
        float exchange_rate;
        std::istringstream ss(value);
        if (!(ss >> exchange_rate))
            throw std::runtime_error("Error: failed to convert exchange rate to float");
        this->_exchangeRates.insert(std::pair<std::string, float>(date, exchange_rate));
    }
}

int BitcoinExchange::isValidDate(std::string const &date)
{
    if ((date.length() != 10) || (date[4] != '-') || (date[7] != '-'))
        return (0);
    int year, month, day;
    char separator;
    std::istringstream(date) >> year >> separator >> month >> separator >> day;

    if ((year < 0) || (month < 1 || month > 12) || (day < 1 || day > 31))
        return (0);
    if ((month == 2) && (year % 4 == 0) && (day > 29))
        return (0);
    if ((month == 2) && (year % 4 != 0) && (day > 28))
        return (0);
    return (1);
}
