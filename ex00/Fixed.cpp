/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosselk <lgosselk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 10:56:21 by lgosselk          #+#    #+#             */
/*   Updated: 2024/04/04 10:20:32 by lgosselk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/* Construtors and Destructor */

Fixed::Fixed( void ): _number(0) {
	std::cout << "Default constructor called" << std::endl;
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

/* Getters */

int	Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_number);
}

/* Setters */

void	Fixed::setRawBits( int const raw ) {
	this->_number = raw;
}
