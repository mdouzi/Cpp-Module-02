/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouzi < mdouzi@student.1337.ma>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 03:21:04 by mdouzi            #+#    #+#             */
/*   Updated: 2023/10/30 19:45:47 by mdouzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

// constructors
Fixed::Fixed(void) : _fixed(0)
{
    // std::cout << "Default constructor called" << std::endl;
}


Fixed::Fixed(Fixed const &src)
{
    // std::cout << "Copy constructor called" << std::endl;
    this->_fixed = src._fixed;
}

Fixed::Fixed(int const intrep)
{
    // std::cout << "Fixed Int Constructor called" << std::endl;
    this->_fixed = intrep << this->fraBits;
}

Fixed::Fixed(float const floatrep)
{
    // std::cout << "Fixed Float Constructor called" << std::endl;
    this->_fixed = (int)roundf(floatrep * (1 << fraBits));
}
//end constructors




Fixed::~Fixed(void)
{
    // std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
    // std::cout << "getRawBits member function called" << std::endl;
    return (this->_fixed);
}

void Fixed::setRawBits(const int  raw)
{
    // std::cout << "setRawBits member function called" << std::endl;
    this->_fixed = raw;
}




// convert
float Fixed::toFloat(void) const
{
    float res = (float)this->_fixed / (1 << this->fraBits);
    return res;
}

int Fixed::toInt(void) const
{
    int res = this->_fixed >> this->fraBits;
    return(res);
}
//end convert



// operatoors 
Fixed &Fixed::operator=(const Fixed &src) 
{
    // std::cout << "Assignation operator called" << std::endl;
    this->_fixed = src.getRawBits();
    return (*this);
}



std::ostream &operator<<(std::ostream &o, Fixed const &fixed)
{
    o << fixed.toFloat();
    return o;
}

bool Fixed::operator>(const Fixed &fixed) const
{
    return (this->_fixed > fixed.getRawBits());
}

bool Fixed::operator>=(const Fixed &fixed) const
{
    return (this->_fixed >= fixed.getRawBits());
}

bool Fixed::operator<(const Fixed &fixed) const
{
    return (this->_fixed < fixed.getRawBits());
}

bool Fixed::operator<=(const Fixed &fixed) const
{
    return (this->_fixed <= fixed.getRawBits());
}

bool Fixed::operator==(const Fixed &fixed) const
{
    return (this->_fixed == fixed.getRawBits());
}

bool Fixed::operator!=(const Fixed &fixed) const
{
    return (this->_fixed != fixed.getRawBits());
}

Fixed Fixed::operator+(const Fixed &src) const
{
    return (Fixed(this->toFloat() + src.toFloat()));
}

Fixed Fixed::operator-(const Fixed &src) const
{
    return (Fixed(this->toFloat() - src.toFloat()));
}

Fixed Fixed::operator*(const Fixed &src) const
{
    return ((this->toFloat() * src.toFloat()));
}

Fixed Fixed::operator/(const Fixed &src) const
{
    return (Fixed(this->toFloat() / src.toFloat()));
}

// end operators



// Increment
Fixed	Fixed::operator++()
{
	this->_fixed++;
	return (*this);
}

Fixed	Fixed::operator--()
{
	this->_fixed--;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed tmp = *this;
	++this->_fixed;
	return (tmp);
}

Fixed	Fixed::operator--(int)
{
	Fixed tmp = *this;
	--this->_fixed;
	return (tmp);
}



// Max && Min
Fixed &Fixed::min(Fixed &obj1, Fixed &obj2)
{
    
    if(obj1._fixed > obj2._fixed)
        return(obj2);
    else if(obj1._fixed < obj2._fixed)
        return(obj1);
    else
        return(obj1);
}

Fixed const &Fixed::min(Fixed const &obj1, Fixed const &obj2)
{
    if (obj1 < obj2)
        return obj1;
    else
        return obj2;
}
// Max && Min
Fixed &Fixed::max(Fixed &obj1, Fixed &obj2)
{
    if(obj1._fixed > obj2._fixed)
        return(obj1);
    else if(obj2._fixed > obj1._fixed)
        return(obj2);
    else
        return(obj1);
}

Fixed const &Fixed::max(Fixed const &obj1, Fixed const &obj2)
{
    if(obj1 < obj2)
        return obj2;
    else
        return obj1;
}
// end Max && Min

