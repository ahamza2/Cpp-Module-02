#include "Fixed.hpp"

int main( void )
{
    Fixed a(45.75f);
	// a.getRawBits();
    // Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    std::cout << a.getRawBits() << std::endl;
    // std::cout << ++a << std::endl;
    // std::cout << a << std::endl;
    // std::cout << a++ << std::endl;
    // std::cout << a << std::endl;
    // std::cout << b << std::endl;
    // std::cout << Fixed::max( b, a ) << std::endl;
    return 0;
}