/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelhota@student.42perpignan.fr            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 23:14:41 by gdelhota          #+#    #+#             */
/*   Updated: 2026/11/06 01:37:54 by gdelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor.hpp"
#include <functional>
#include <iostream>

int getDegree(std::map<int, float> equation)
{
	std::map<int, float>::iterator ite = (--equation.end());
	while (ite->second == 0 && ite != equation.begin())
		ite--;
	return ite->first;
}

void solveFirstDegree(std::map<int, float> equation)
{
	float a = equation[1],
		  b = equation[0];
	float res = -b / a;
	std::cout << std::endl;
	std::cout << a << "X = " << -b << std::endl;
	std::cout << "X = " << -b << "/" << a << std::endl;
	std::cout << std::endl;
	std::cout << "The solution is:" << std::endl;
	std::cout << res << std::endl;
}

void solveSecondDegree(std::map<int, float> equation)
{
	float a = equation[2],
		  b = equation[1],
		  c = equation[0];
	float delta = b * b - 4 * a * c;
	float res1, res2;
	std::cout << std::endl;
	std::cout << "D = b^2 - 4ac" << std::endl;
	std::cout << "D = " << b << "^2 - 4 * " << a << " * " << c << std::endl;
	std::cout << "D = " << delta << std::endl;
	std::cout << std::endl;
	if (delta == 0)
	{
		//mathematical nonsense to prevent -0 from showing up
		if (b == 0)
			b = -b;
		res1 = -b / 2 * a;
		std::cout << "Discriminant is zero, the solution is:" << std::endl;
		std::cout << "r = -b / 2a" << std::endl;
		std::cout << "r = " << -b << " / (2 * " << a << ")" << std::endl;
		std::cout << "r = " << res1 << std::endl;
	}
	else if (delta > 0)
	{
		if (b == 0)
			b = -b;
		res1 = (-b - std::sqrt(delta)) / (2 * a);
		res2 = (-b + std::sqrt(delta)) / (2 * a);
		prettyResolution(a, b, delta);
		std::cout << res1 << std::endl;
		std::cout << res2 << std::endl;
	}
	else
	{
		if (b == 0)
			b = -b;
		res1 = -b / (2 * a);
		float comp = std::sqrt(-delta) / (2 * a);
		prettyResolution(a, b, delta);
		std::cout << res1 << " + " << comp << "i" << std::endl;
		std::cout << res1 << " - " << comp << "i" << std::endl;
	}
}

void solve(std::map<int, float> equation)
{
	int degree = getDegree(equation);
	if (equation[degree] == 0)
	{
		std::cout << "Any real number is a solution." << std::endl;
		return ;
	}
	if (degree == 0)
	{
		std::cout << "No solution." << std::endl;
		return ;
	}
	std::cout << "Polynomial degree: " << degree << std::endl;
	if (degree > 2)
	{
		std::cout << "The polynomial degree is strictly greater than 2, I can't solve." << std::endl;
		return;
	}
	std::cout << "Resolution steps:" << std::endl;
	prettyPrint(equation);
	if (degree == 1)
		solveFirstDegree(equation);
	else
		solveSecondDegree(equation);
}
