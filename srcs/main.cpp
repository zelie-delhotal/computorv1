/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelhota@student.42perpignan.fr            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 17:32:25 by gdelhota          #+#    #+#             */
/*   Updated: 2026/11/04 21:23:39 by gdelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor.hpp"
using namespace std;

int main(int ac, char **av)
{
	if (ac > 2)
	{
		cout << "Too many arguments (Did you forget quotes?)" << endl;
		exit(1);
	}
	map<int, int> res = parse(av[1]);
	print(res);
}
