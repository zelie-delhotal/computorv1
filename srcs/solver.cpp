/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelhota@student.42perpignan.fr            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 23:14:41 by gdelhota          #+#    #+#             */
/*   Updated: 2026/11/05 03:27:35 by gdelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor.hpp"
#include <cmath>

int getDegree(std::map<int, float> equation)
{
	std::map<int, float>::iterator ite = (--equation.end());
	while (ite->second == 0 && ite != equation.begin())
		ite--;
	return ite->first;
}

void solveFirstDegree(std::map<int, float> equation)
{
	float res = - equation[0] / equation[1];
	std::cout << "The solution is:" << std::endl;
	std::cout << res << std::endl;
}

void solveSecondDegree(std::map<int, float> equation)
{
	float a = equation[2],
		  b = equation[1],
		  c = equation[0];
	float delta = b * b - 4 * a * c;
	float res;
	if (delta == 0)
	{
		std::cout << "Discriminant is zero, the solution is:" << std::endl;
		res = -b / 2 * a;
		std::cout << res << std::endl;
	}
	else if (delta > 0)
	{
		std::cout << "Discriminant is strictly positive, the two solution are:" << std::endl;
		res = (-b - std::sqrt(delta)) / (2 * a);
		std::cout << res << std::endl;
		res = (-b + std::sqrt(delta)) / (2 * a);
		std::cout << res << std::endl;
	}
	else
	{
		std::cout << "Discriminant is strictly negative, the two complex solution are:" << std::endl;
		res = -b / (2 * a);
		float comp = std::sqrt(-delta) / (2 * a);
		std::cout << res << " + " << comp << "i" << std::endl;
		std::cout << res << " - " << comp << "i" << std::endl;
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
	if (degree == 1)
		solveFirstDegree(equation);
	else
		solveSecondDegree(equation);
}
