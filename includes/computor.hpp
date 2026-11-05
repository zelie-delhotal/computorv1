/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computor.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelhota@student.42perpignan.fr            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 18:39:08 by gdelhota          #+#    #+#             */
/*   Updated: 2026/11/05 22:02:51 by gdelhota         ###   ########.fr       */
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

std::map<int, float> parse(std::string);
void printReduced(std::map<int, float>);
int getDegree(std::map<int, float>);
void solve(std::map<int, float>);

#endif
