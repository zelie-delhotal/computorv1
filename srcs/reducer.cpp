/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reducer.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelhota@student.42perpignan.fr            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 18:54:25 by gdelhota          #+#    #+#             */
/*   Updated: 2026/11/05 02:52:02 by gdelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor.hpp"

std::pair<int, float> parseSingle(std::string equation, int *i, int sign)
{
	float n = 1, degree = 0;
	while (isspace(equation[*i]))
		(*i)++;
	while (equation[*i] && equation[*i] != '+' && equation[*i] != '=' && equation[*i] != '-')
	{
		if (equation[*i] == 'X' && equation[*i + 1] == '^' && isdigit(equation[*i + 2])) {
			(*i) += 2;
			degree += atoi(&equation[*i]);
			(*i)++;
		}
		else if (isdigit(equation[*i]) || (equation[*i] == '-' && isdigit(equation[*i + 1])))
		{
			n *= atof(&equation[*i]) * sign;
			if (equation[*i] == '-')
				(*i)++;
			while (isdigit(equation[*i])) {
				(*i)++;
			}
			if (equation[*i] == '.')
				(*i)++;
			while (isdigit(equation[*i])) {
				(*i)++;
			}
		}
		else {
			return {-1, -1};
		}
		while (isspace(equation[*i]))
			(*i)++;
		if (equation[*i] == '*')
			(*i)++;
		while (isspace(equation[*i]))
			(*i)++;
	}
	return {degree, n};
}

std::map<int, float> parse(std::string equation)
{
	std::map<int, float> res;
	std::pair<int, float> single;
	int i = 0, sign = 1;
	bool rhs = false;
	while (equation[i])
	{
		single = parseSingle(equation, &i, sign);
		if (single.first == -1)
			return {};
		if (res.count(single.first) == 0)
			res.insert(single);
		else
			res[single.first] += single.second;
		if (equation[i])
		{
			if (equation[i] == '=')
			{
				if (rhs)
					return {};
				sign = 1;
				rhs = true;
			}
			else if (equation[i] == '-')
				sign =  -1;
			else if (equation[i] == '+')
				sign = 1;
			if (rhs)
				sign *= -1;
			i++;
		}
	}
	if (!rhs)
		return {};
	return res;
}

void printReduced(std::map<int, float> equation)
{
	bool first = true;
	float degree = 0;
	std::cout << "Reduced form: ";
	for (auto factor : equation)
	{
		while (factor.first > degree) {
			if (!first)
				std::cout << " + ";
			first = false;
			std::cout << "0 * X^" << degree;
			degree++;
		}
		if (!first)
			std::cout << " + ";
		first = false;
		std::cout << factor.second << " * X^" << factor.first;
		degree++;
	}
	std::cout << " = 0" << std::endl;
}
