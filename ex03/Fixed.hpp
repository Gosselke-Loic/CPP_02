/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosselk <lgosselk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 11:46:52 by lgosselk          #+#    #+#             */
/*   Updated: 2024/04/03 15:49:29 by lgosselk         ###   ########.fr       */
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
		void	setRawBits( const int raw );

		Fixed	&operator=( const Fixed &copy );

		Fixed	&operator++( void ); /* pre */
		Fixed	&operator--( void ); /* pre */
		Fixed	operator++( int value ); /* post */
		Fixed	operator--( int value ); /* post */

		Fixed	operator+( const Fixed &copy ) const;
		Fixed	operator-( const Fixed &copy ) const;
		Fixed	operator*( const Fixed &copy ) const;
		Fixed	operator/( const Fixed &copy ) const;

		bool	operator>( const Fixed &copy ) const;
		bool	operator<( const Fixed &copy ) const;
		bool	operator>=( const Fixed &copy ) const;
		bool	operator<=( const Fixed &copy ) const;
		bool	operator==( const Fixed &copy ) const;
		bool	operator!=( const Fixed &copy ) const;

		static Fixed   &min( Fixed &a, Fixed &b );
		static Fixed   &max( Fixed &a, Fixed &b );
		static const Fixed   &min( Fixed const &a, Fixed const &b );
		static const Fixed   &max( Fixed const &a, Fixed const &b );
};

std::ostream& operator<<( std::ostream& stream, const Fixed &fixed );

#endif