/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosselk <lgosselk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 11:46:52 by lgosselk          #+#    #+#             */
/*   Updated: 2024/03/28 10:54:34 by lgosselk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

# include <cmath>
# include <iostream>

class	Fixed {
	private:
		int					_number;
        static const int	_bit = 8;
	public:
		Fixed( void );
		~Fixed( void );
		Fixed( const int num );
		Fixed( const float f_num );
		Fixed( const Fixed &copy );
		int		toInt( void ) const;
		float	toFloat( void ) const;
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		Fixed	&operator=( Fixed const &copy );
};

std::ostream& operator<<( std::ostream& stream, const Fixed &fixed );

#endif