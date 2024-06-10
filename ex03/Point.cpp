/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosselk <lgosselk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 11:49:33 by lgosselk          #+#    #+#             */
/*   Updated: 2024/03/28 10:48:42 by lgosselk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

Point::Point( void ): _x(0), _y(0)
{}

Point::Point( const Point &copy ): _x(copy.getX()), _y(copy.getY())
{}

Point::Point( const float f_x, const float f_y ): _x(f_x), _y(f_y)
{}

Point::~Point( void ) 
{}

Point	&Point::operator=( const Point &copy ) {
	if (this != &copy) {
        ( Fixed ) this->_x = copy.getX();
        ( Fixed ) this->_y = copy.getY();
    }
	return (*this);
}

Fixed Point::getX( void ) const {
    return (this->_x);
}

Fixed Point::getY( void ) const {
    return (this->_y);
}