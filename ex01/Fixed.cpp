/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouzi < mdouzi@student.1337.ma>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 03:21:04 by mdouzi            #+#    #+#             */
/*   Updated: 2023/10/30 19:16:34 by mdouzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : _fixed(0)
{
    std::cout << "Default constructor called" << std::endl;
}


Fixed::Fixed(Fixed const &src)
{
    std::cout << "Copy constructor called" << std::endl;
    this->_fixed = src._fixed;
}

Fixed::Fixed(int const intrep)
{
    std::cout << "Fixed Int Constructor called" << std::endl;
    this->_fixed = intrep << this->fraBits;
}

Fixed::Fixed(float const floatrep)
{
    std::cout << "Fixed Float Constructor called" << std::endl;
    this->_fixed = floatrep * (1 << fraBits);
}

Fixed &Fixed::operator=(const Fixed &src) 
{
    std::cout << "Assignation operator called" << std::endl;
    this->_fixed = src.getRawBits();
    return *this;
}

Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;
}


int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->_fixed);
}

void Fixed::setRawBits(const int  raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    this->_fixed = raw;
}

float Fixed::toFloat(void) const
{
    float res = (float)_fixed / (float)(1 << this->fraBits);
    return res;
}

int Fixed::toInt(void) const
{
    int res = _fixed >> this->fraBits;
    return(res);
}

std::ostream &operator<<(std::ostream &o, Fixed const &fixed)
{
    o << fixed.toFloat();
    return o;
}
