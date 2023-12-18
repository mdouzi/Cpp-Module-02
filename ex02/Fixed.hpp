/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouzi < mdouzi@student.1337.ma>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 03:18:08 by mdouzi            #+#    #+#             */
/*   Updated: 2023/10/27 10:36:11 by mdouzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
#define FIXED_H

#include <iostream> 



class Fixed
{
    private:
        int _fixed;
        static const int fraBits = 8;
    public:
        Fixed();
        Fixed(int const intrep);
        Fixed(float const floatrep);
        Fixed(const Fixed& other);
        ~Fixed();

        float toFloat(void) const;
        int toInt(void) const;
        
        Fixed &operator=(const Fixed &src);
        
        // Comparison
        bool operator>(const Fixed &fixed) const;
        bool operator>=(const Fixed &fixed) const;
        bool operator<(const Fixed &fixed) const;
        bool operator<=(const Fixed &fixed) const;
        bool operator==(const Fixed &fixed) const;
        bool operator!=(const Fixed &fixed) const;

        // Arithmetic 
        Fixed operator+(const Fixed &fixed) const;
        Fixed operator-(const Fixed &fixed) const;
        Fixed operator*(const Fixed &fixed) const;
        Fixed operator/(const Fixed &fixed) const;

        // Increment / Decrement
        Fixed operator++(void);
        Fixed operator++(int const);
        Fixed operator--(void);
        Fixed operator--(int const);

        // Min / max
        static Fixed &min(Fixed &obj1, Fixed &obj2);
        static Fixed const &min(Fixed const &obj1, Fixed const &obj2);
        static Fixed &max(Fixed &obj1, Fixed &obj2);
        static Fixed const &max(Fixed const &obj1, Fixed const &obj2);


        int getRawBits(void) const;
        void setRawBits(const int raw);
                
};

std::ostream    &operator<<(std::ostream &o, Fixed const &fixed);
#define LEAST_INCREMENT_POSSIBLE (1.0 / (1 << Fixed::fraBits))
#endif