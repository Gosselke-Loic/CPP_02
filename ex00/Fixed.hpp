/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosselk <lgosselk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 10:56:30 by lgosselk          #+#    #+#             */
/*   Updated: 2024/03/28 10:54:00 by lgosselk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

# include <iostream>

class	Fixed {
	private:
		int					_number;
        static const int	_bit = 8;
	public:
		Fixed( void );
		~Fixed( void );
		Fixed( Fixed const &copy );
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		Fixed	&operator=( Fixed const &copy );
};

#endif