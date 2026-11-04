/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computor.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelhota@student.42perpignan.fr            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 18:54:25 by gdelhota          #+#    #+#             */
/*   Updated: 2026/11/04 21:31:38 by gdelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor.hpp"

std::pair<int, int> parseSingle(std::string equation, int *index)
{
	int n = 1, degree = 0;
	while (isspace(equation[*index]))
		(*index)++;
	while (equation[*index] && equation[*index] != '+')
	{
		if (equation[*index] == 'X' && equation[*index + 1] == '^') {
			(*index) += 2;
			degree += atoi(&equation[*index]);
			(*index)++;
		}
		else if (isdigit(equation[*index])) {
			n *= atoi(&equation[*index]);
			while (isdigit(equation[*index])) {
				(*index)++;
			}
		}
		else {
			return {-1, -1};
		}
		while (isspace(equation[*index]))
			(*index)++;
		if (equation[*index] == '*')
			(*index)++;
		while (isspace(equation[*index]))
			(*index)++;
	}
	return {degree, n};
}

std::map<int, int> parse(std::string equation)
{
	std::map<int, int> res;
	std::pair<int, int> single;
	int i = 0;
	while (equation[i])
	{
		single = parseSingle(equation, &i);
		if (res.count(single.first) == 0)
			res.insert(single);
		else
			res[single.first] += single.second;
		if (equation[i])
			i++;
	}
	return res;
}

void print(std::map<int, int> equation)
{
	bool first = true;
	int degree = 0;
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
	std::cout << std::endl;
}
