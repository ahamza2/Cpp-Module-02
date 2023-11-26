/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haarab <haarab@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 17:36:21 by haarab            #+#    #+#             */
/*   Updated: 2023/11/12 21:29:57 by haarab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int value;
		static const int bits = 8;
		
	public:
		Fixed();
		Fixed(const Fixed &fixed);
		Fixed & operator=(const Fixed & fixed);
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		~Fixed();

};


#endif