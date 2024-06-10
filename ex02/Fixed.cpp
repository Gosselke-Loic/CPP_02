/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosselk <lgosselk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 11:46:43 by lgosselk          #+#    #+#             */
/*   Updated: 2024/04/04 10:21:40 by lgosselk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/* Construtors and Destructor */

Fixed::Fixed( void ): _number(0)
{}

Fixed::Fixed( const int num ): _number(num << this->_bit)
{}

Fixed::Fixed( const float f_num ): _number( std::roundf( f_num * ( 1 << this->_bit ) ) )
{}

Fixed::Fixed( Fixed const &copy ) {
	*this = copy;
}

Fixed::~Fixed( void )
{}

/* Assigment overload operator */

Fixed	&Fixed::operator=( Fixed const &copy ) {
	this->_number = copy.getRawBits();
	return (*this);
}

/* Increment/Decrement overload operators */

Fixed	&Fixed::operator++( void ) {
	this->setRawBits(this->getRawBits() + 1);
	return (*this);
}

Fixed	&Fixed::operator--( void ) {
	this->setRawBits(this->getRawBits() - 1);
	return (*this);
}

Fixed	Fixed::operator++( int value ) {
	Fixed temp = *this;

	if (!value)
		value = 1;
	this->setRawBits(this->getRawBits() + value);
	return (temp);
}

Fixed	Fixed::operator--( int value ) {
	Fixed temp = *this;

	if (!value)
		value = 1;
	this->setRawBits(this->getRawBits() - value);
	return (temp);
}

/* Arithmetic overload operators */

Fixed	Fixed::operator+( const Fixed &copy ) const {
	Fixed	res(this->toFloat() + copy.toFloat());
	return (res);
}

Fixed	Fixed::operator-( const Fixed &copy ) const {
	Fixed	res(this->toFloat() - copy.toFloat());
	return (res);
}

Fixed	Fixed::operator*( const Fixed &copy ) const {
	Fixed	res(this->toFloat() * copy.toFloat());
	return (res);
}

Fixed	Fixed::operator/( const Fixed &copy ) const {
	Fixed	res(this->toFloat() / copy.toFloat());
	return (res);
}

/* Comparison overload operators */

bool	Fixed::operator>( const Fixed &copy ) const {
	return (this->getRawBits() > copy.getRawBits());
}

bool	Fixed::operator<( const Fixed &copy ) const {
	return (this->getRawBits() < copy.getRawBits());
}

bool	Fixed::operator>=( const Fixed &copy ) const {
	return (this->getRawBits() >= copy.getRawBits());
}

bool	Fixed::operator<=( const Fixed &copy ) const {
	return (this->getRawBits() <= copy.getRawBits());
}

bool	Fixed::operator==( const Fixed &copy ) const {
	return (this->getRawBits() == copy.getRawBits());
}

bool	Fixed::operator!=( const Fixed &copy ) const {
	return (this->getRawBits() != copy.getRawBits());
}

/* Output stream overload */

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

/* Min/Max methods */

Fixed &Fixed::min( Fixed &a, Fixed &b ) {
	if (a < b)
		return (a);
	return (b);
}

Fixed &Fixed::max( Fixed &a, Fixed &b ) {
	if (a > b)
		return (a);
	return (b);
}

const Fixed &Fixed::max( const Fixed &a, const Fixed &b ) {
	if (a > b)
		return (a);
	return (b);
}

const Fixed &Fixed::min( const Fixed &a, const Fixed &b ) {
	if (a < b)
		return (a);
	return (b);
}