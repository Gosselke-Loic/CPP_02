/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosselk <lgosselk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 11:49:26 by lgosselk          #+#    #+#             */
/*   Updated: 2024/03/27 15:56:28 by lgosselk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_H
# define POINT_H

# include "Fixed.hpp"

class   Point {
	private:
		const Fixed _x;
		const Fixed	_y;
	public:
		Point( void );
		~Point( void );
		Fixed	getY( void ) const;
		Fixed	getX( void ) const;
		Point( const Point &copy );
		Point	&operator=( const Point &copy );
		Point( const float f_x, const float f_y );
};

bool	bsp( Point const a, Point const b, Point const c, Point const point );

#endif