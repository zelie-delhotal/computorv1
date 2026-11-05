/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computor.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelhota@student.42perpignan.fr            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 18:39:08 by gdelhota          #+#    #+#             */
/*   Updated: 2026/11/05 02:32:56 by gdelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPUTOR_HPP
# define COMPUTOR_HPP

#include <string>
#include <map>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <string>
#include <map>

void printReduced(std::map<int, float>);
std::map<int, float> parse(std::string);
void solve(std::map<int, float>);

#endif
