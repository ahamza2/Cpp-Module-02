#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
    private:
        int value;
		static const int bits = 8;

    public:
        Fixed();
		Fixed(const int number);
		Fixed(const float number);
		Fixed(const Fixed &fixed);
		Fixed & operator=(const Fixed & fixed);
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		float toFloat( void ) const;
		int toInt( void ) const;
		~Fixed();

		// Comparison operators
		bool operator>(const Fixed& other) const;
		bool operator<(const Fixed& other) const;
		bool operator>=(const Fixed& other) const;
		bool operator<=(const Fixed& other) const;
		bool operator==(const Fixed& other) const;
		bool operator!=(const Fixed& other) const;
		
		// arithmetic operators
		Fixed  operator+(const Fixed &fixed) const ;
		Fixed  operator-(const Fixed &fixed) const ;
		Fixed  operator*(const Fixed &fixed) const ;
		Fixed  operator/(const Fixed &fixed) const ;

		// increment and decrement operators
		Fixed & operator++();
		Fixed operator++(int);
		Fixed & operator--();
		Fixed operator--(int);

		// Static member functions
		static Fixed& min(Fixed& a, Fixed& b);
		static const Fixed& min(const Fixed& a, const Fixed& b);
		static Fixed& max(Fixed& a, Fixed& b);
		static const Fixed& max(const Fixed& a, const Fixed& b);

};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif