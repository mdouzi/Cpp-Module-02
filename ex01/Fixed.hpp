/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouzi < mdouzi@student.1337.ma>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 03:18:08 by mdouzi            #+#    #+#             */
/*   Updated: 2023/10/24 05:27:59 by mdouzi           ###   ########.fr       */
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
        
        int getRawBits(void) const;
        void setRawBits(const int raw);
        
};

std::ostream    &operator<<(std::ostream &o, Fixed const &fixed);

#endif