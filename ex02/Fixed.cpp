#include "Fixed.hpp"

Fixed::Fixed()
{
	// std::cout << "Default constructor called" << std::endl;
	this->value = 0;
}

Fixed::Fixed(const int number) : value(number << bits)
{
	// std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float number) : value(roundf(number * (1 << bits)))
{
	// std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed & other)
{	
	// std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed & Fixed::operator=(const Fixed & other)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
    	value = other.value;
    }
	return *this;
}

Fixed::~Fixed(){
	// std::cout << "Destructor called" << std::endl;
}


int Fixed::getRawBits(void) const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return (this->value);
}


void Fixed::setRawBits(int const raw)
{
	this->value = raw;
}

int Fixed::toInt( void ) const
{
    return (value >> bits);
}

float Fixed::toFloat( void ) const
{
    return static_cast<float>(value) / ( 1 << bits);
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
    os << fixed.toFloat();
    return os;
}

// Comparison operators

bool Fixed::operator>(const Fixed& other) const {
	return value > other.value;
}

bool Fixed::operator<(const Fixed& other) const {
	return value < other.value;
}

bool Fixed::operator>=(const Fixed& other) const {
	return value >= other.value;
}

bool Fixed::operator<=(const Fixed& other) const {
	return value <= other.value;
}

bool Fixed::operator==(const Fixed& other) const {
	return value == other.value;
}

bool Fixed::operator!=(const Fixed& other) const {
	return value != other.value;
}

// arithmetic operators

Fixed  Fixed::operator+(const Fixed& fixed) const {
	return (this->toFloat() + fixed.toFloat());
}

Fixed  Fixed::operator-(const Fixed& fixed) const {
	return Fixed(this->toFloat() - fixed.toFloat());

}

Fixed  Fixed::operator*(const Fixed& fixed) const{
	return Fixed(this->toFloat() * fixed.toFloat());

}

Fixed  Fixed::operator/(const Fixed& fixed) const {
	return Fixed(this->toFloat() / fixed.toFloat());

}

// increment and decrement operators

Fixed & Fixed::operator++() {
	++value;
	return *this;
}

Fixed	Fixed::operator++(int) {
	Fixed temp(*this);
	++(*this);
	return temp;
}

Fixed &	Fixed::operator--() {
	--value;
	return *this;
}

Fixed	Fixed::operator--(int) {
	Fixed temp(*this);
	--(*this);
	return temp;
}

// Static member functions
Fixed& Fixed::min(Fixed& a, Fixed& b) {
	return (a < b) ? a : b;
	// if (a.getRawBits() < b.getRawBits())
	// 	return(a);
	// return (b);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
	return (a < b) ? a : b;
	// if (a.getRawBits() < b.getRawBits())
	// 	return(a);
	// return (b);
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
	return (a > b) ? a : b;
	// if (a.getRawBits() > b.getRawBits())
	// 	return(a);
	// return (b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
	return (a > b) ? a : b;
	// if (a.getRawBits() > b.getRawBits())
	// 	return(a);
	// return (b);
}