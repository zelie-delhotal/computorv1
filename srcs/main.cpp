/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelhota@student.42perpignan.fr            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 17:32:25 by gdelhota          #+#    #+#             */
/*   Updated: 2026/11/05 03:07:10 by gdelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor.hpp"
#include <string>
using namespace std;

int main(int ac, char **av)
{
	if (ac > 2)
	{
		cout << "Too many arguments (Did you forget quotes?)" << endl;
		exit(1);
	}
	string equation;
	if (ac == 2)
		equation = av[1];
	else
	{
		cout << "Reading equation from stdin:" << endl;
		getline(cin, equation);
	}
	map<int, float> res = parse(equation);
	if (res.size() == 0)
	{
		cout << "Parsing error" << endl;
		return 1;
	}
	printReduced(res);
	solve(res);
}
