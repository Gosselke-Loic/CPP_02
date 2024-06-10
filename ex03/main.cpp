/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosselk <lgosselk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 11:47:06 by lgosselk          #+#    #+#             */
/*   Updated: 2024/04/04 10:08:43 by lgosselk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main( void ) {
    if (bsp( Point(0, 0), Point(-5, 5), Point(-5, 0), Point(-4, 0) ) == true)
        std::cout << "this point is in the triangle" << std::endl;
    else
        std::cout << "this point is not in the triangle" << std::endl;
    return (0);
}