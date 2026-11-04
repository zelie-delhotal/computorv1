/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computor.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelhota@student.42perpignan.fr            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 18:39:08 by gdelhota          #+#    #+#             */
/*   Updated: 2026/11/04 21:19:11 by gdelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPUTOR_HPP
# define COMPUTOR_HPP

#include <string>
#include <map>
#include <cstdlib>
#include <iostream>
#include <string>
#include <map>

void print(std::map<int, int>);
std::map<int, int> parse(std::string equation);
std::pair<int, int> parseSingle(std::string equation, int *index);

#endif
