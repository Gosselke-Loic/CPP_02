/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosselk <lgosselk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 11:46:43 by lgosselk          #+#    #+#             */
/*   Updated: 2024/04/04 10:21:11 by lgosselk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/* Construtors and Destructor */

Fixed::Fixed( void ): _number(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const int num ): _number(num << this->_bit) {
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed( const float f_num ): _number( std::roundf( f_num * ( 1 << this->_bit ) ) ) {
    std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed( Fixed const &copy ) {
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed::~Fixed( void ) {
	std::cout << "Destructor called" << std::endl;
}

/* Overload operator */

Fixed	&Fixed::operator=( Fixed const &copy ) {
	std::cout << "Copy assigment operator called" << std::endl;
	this->_number = copy.getRawBits();
	return (*this);
}

std::ostream& operator<<( std::ostream& stream, const Fixed &fixed ) {
    return (stream << fixed.toFloat());
}

/* Getters */

int	    Fixed::getRawBits( void ) const {
	return (this->_number);
}

/* Setters */

void	Fixed::setRawBits( int const raw ) {
	this->_number = raw;
}

/* Methods */

int     Fixed::toInt( void ) const {
    return (this->getRawBits() >> this->_bit);
}

float   Fixed::toFloat( void ) const {
    return (static_cast<float>( this->getRawBits() ) / ( 1 << this->_bit ));
}