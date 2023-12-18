/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouzi < mdouzi@student.1337.ma>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 03:18:08 by mdouzi            #+#    #+#             */
/*   Updated: 2023/10/23 06:23:09 by mdouzi           ###   ########.fr       */
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
        Fixed(const Fixed& other);
        int getRawBits(void) const;
        Fixed &operator=(const Fixed &src);
        void setRawBits(const int raw);
        ~Fixed();
};

#endif