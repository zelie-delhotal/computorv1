/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reducer.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelhota@student.42perpignan.fr            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 18:54:25 by gdelhota          #+#    #+#             */
/*   Updated: 2026/11/06 05:33:36 by gdelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor.hpp"
#include <cmath>
#include <cstddef>
#include <cstdio>
#include <iostream>

std::pair<int, float> parseSingle(std::string equation, int *i)
{
	float n = 1, degree = 0;
	while (isspace(equation[*i]))
		(*i)++;
	if (!equation[*i] || equation[*i] == '+' || equation[*i] == '=')
		return {-1, -1};
	if (equation[*i] == '-')
		return {0, 0};
	while (equation[*i] && equation[*i] != '+' && equation[*i] != '=' && equation[*i] != '-')
	{
		if (equation[*i] == 'X' && equation[*i + 1] == '^' && isdigit(equation[*i + 2])) {
			(*i) += 2;
			degree += atoi(&equation[*i]);
			(*i)++;
		}
		else if (equation[*i] == 'X') {
			degree += 1;
			(*i)++;
		}
		else if (isdigit(equation[*i]) || (equation[*i] == '-' && isdigit(equation[*i + 1])))
		{
			n *= atof(&equation[*i]);
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
	int i = 0;
	float sign = 1;
	bool rhs = false;
	while (equation[i])
	{
		single = parseSingle(equation, &i);
		if (single.first == -1)
			return {};
		single.second *= sign;
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
	bool isNull = true;
	std::cout << "Reduced form: ";
	for (std::map<int, float>::iterator factor = equation.end(); factor != equation.begin();)
	{
		factor--;
		if (factor->second != 0)
			isNull = false;
		else
		{
			std::map<int, float>::iterator temp = factor;
			factor++;
			equation.erase(temp);
		}
	}
	if (isNull)
	{
		std::cout << "0 * X^0 = 0" << std::endl;
		return;
	}
	float degree = 0;
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
		{
			std::cout << (factor.second>=0?" + ":" - ");
			std::cout << (factor.second<0?-factor.second:factor.second) << " * X^" << factor.first;
		}
		else 
		{
			first = false;
			std::cout << factor.second << " * X^" << factor.first;
		}
		degree++;
	}
	std::cout << " = 0" << std::endl;
}

void prettyPrint(std::map<int, float> e)
{
	bool first = true;
	for (auto factor = e.end(); factor != e.begin();)
	{
		factor--;
		if (factor->second == 0)
			continue;
		if (!first)
		{
			std::cout << (factor->second>=0?" + ":" - ");
			if (factor->first == 0 || (factor->second != 1 && factor->second != -1))
				std::cout << (factor->second<0?-factor->second:factor->second);
			if (factor->first == 1)
				std::cout << "X";
			else if (factor->first > 1)
				std::cout<< "X^" << factor->first;
		}
		else 
		{
			first = false;
			if (factor->first == 0 || (factor->second != 1 && factor->second != -1))
				std::cout << factor->second;
			if (factor->first == 1)
				std::cout << "X";
			else if (factor->first > 1)
				std::cout << "X^" << factor->first;
		}
	}
	std::cout << " = 0" << std::endl;
}

void prettyFractions(float a, float b, float delta)
{
	bool isComplex = false;

	if (delta < 0)
	{
		isComplex = true;
		delta = -delta;
	}
	if (!isComplex)
	{
		std::cout << "r1 = (" << -b  << " - sqrt(" << delta << ")) / (2 * " << a << ")" << std::endl;
		std::cout << "r2 = (" << -b  << " + sqrt(" << delta << ")) / (2 * " << a << ")" << std::endl;
	}
	else
	{
		std::cout << "r1 = " << -b  << " / (2 * " << a
			<< ") - i(sqrt(" << delta << ") / (2 * " << a << "))" << std::endl;
		std::cout << "r2 = " << -b  << " / (2 * " << a
			<< ") + i(sqrt(" << delta << ")) / (2 * " << a << "))" << std::endl;
	}

	// if Delta is an integer, we can try to reduce the root
	// and print pretty fractions
	float perfectRoot = 0;
	float trash;
	int dCast = (int) delta;
	if (std::modf(delta, &trash) == 0)
	{
		for (int i = 1; i*i<=delta; i++)
		{
			if (dCast % (i*i) == 0)
				perfectRoot = i;
		}
	}

	if (perfectRoot > 1)
	{
		delta /= (perfectRoot * perfectRoot);
		if (!isComplex)
		{
			std::cout << "r1 = (" << -b  << " - ";
			if (perfectRoot >= 1)
				std::cout << perfectRoot;
			if (delta > 1)
				std::cout << "sqrt(" << delta << ")";
			std::cout << " / (2 * " << a << ")" << std::endl;
			std::cout << "r2 = (" << -b  << " + ";
			if (perfectRoot >= 1)
				std::cout << perfectRoot;
			if (delta > 1)
				std::cout << "sqrt(" << delta << ")";
			std::cout << " / (2 * " << a << ")" << std::endl;
		}
		else
		{
			std::cout << "r1 = " << -b  << " / (2 * " << a << ") - ";
			if (perfectRoot >= 1)
				std::cout << perfectRoot;
			if (delta > 1)
				std::cout << "sqrt(" << delta << ")";
			std::cout << "i";
			std::cout << " / (2 * " << a << ")" << std::endl;
			std::cout << "r2 = " << -b  << " / (2 * " << a << ") + ";
			if (perfectRoot >= 1)
				std::cout << perfectRoot;
			if (delta > 1)
				std::cout << "sqrt(" << delta << ")";
			std::cout << "i";
			std::cout << " / (2 * " << a << "))" << std::endl;
		}
	}
}

void prettyResolution(float a, float b, float delta)
{
	(void) a;
	(void) b;
	std::cout << "Discriminant is strictly " << (delta>0?"positive":"negative") 
		<< ", the two " << (delta<0?"complex ":"") << "solutions are:" << std::endl;
	if (delta > 0)
	{
		std::cout << "r1 = (-b - sqrt(D)) / 2a" << std::endl;
		std::cout << "r2 = (-b + sqrt(D)) / 2a" << std::endl;
	}
	else
	{
		std::cout << "r1 = -(b / 2a) - i(sqrt(-D) / 2a)" << std::endl;
		std::cout << "r2 = -(b / 2a) + i(sqrt(-D) / 2a)" << std::endl;
	}
	std::cout << std::endl;
	prettyFractions(a, b, delta);
}
