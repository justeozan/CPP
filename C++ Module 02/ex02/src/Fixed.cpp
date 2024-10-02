#include "../includes/Fixed.hpp"

Fixed::Fixed(void): _number(0)
{
}

Fixed::Fixed(const int n)
{
	_number = n << _position;
}

Fixed::Fixed(const float f)
{
	_number = (int)roundf(f * (1 << _position));
}

Fixed::Fixed(const Fixed& other)
{
	*this = other;
}

Fixed::~Fixed() {
	
}

Fixed& Fixed::operator=(const Fixed& other)
{
	if (this != &other)
		_number = other.getRawBits();
	return (*this);
}

/* COMPARISON */
bool Fixed::operator<(const Fixed& other) const
{
	return (_number < other.getRawBits());
}

bool Fixed::operator<=(const Fixed& other) const
{
	return (_number <= other.getRawBits());
}

bool Fixed::operator>(const Fixed& other) const
{
	return (_number > other.getRawBits());
}

bool Fixed::operator>=(const Fixed& other) const
{
	return (_number >= other.getRawBits());
}

bool Fixed::operator==(const Fixed& other) const
{
	return (_number == other.getRawBits());
}

bool Fixed::operator!=(const Fixed& other) const
{
	return (_number != other.getRawBits());
}

/* OPERATION */
Fixed Fixed::operator+(const Fixed& other) const
{
	Fixed result(_number + other.getRawBits());
	return (result);
}

Fixed Fixed::operator-(const Fixed& other) const
{
	Fixed result(_number - other.getRawBits());
	return (result);
}

Fixed Fixed::operator*(const Fixed& other) const
{
	Fixed result(this->toFloat() * other.toFloat());
	return (result);
}

Fixed Fixed::operator/(const Fixed& other) const
{
	Fixed result(this->toFloat() / other.toFloat());
	return (result);
}

/* FAST OPERATION */
Fixed& Fixed::operator++(void)
{
	_number++;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	_number++;
	return (tmp);
}

Fixed& Fixed::operator--(void)
{
	_number--;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	_number--;
	return (tmp);
}

Fixed& Fixed::min(Fixed& n1, Fixed& n2)
{
	return (n1 < n2 ? n1 : n2);
}

const Fixed& Fixed::min(const Fixed& n1, const Fixed& n2)
{
	return (n1 < n2 ? n1 : n2);
}

Fixed& Fixed::max(Fixed& n1, Fixed& n2)
{
	return (n1 > n2 ? n1 : n2);
}

const Fixed& Fixed::max(const Fixed& n1, const Fixed& n2)
{
	return (n1 > n2 ? n1 : n2);
}

int		Fixed::toInt(void) const
{
	return _number >> _position;
}

float	Fixed::toFloat(void) const
{
	return (float)_number / (1 << _position);
}

int		Fixed::getRawBits(void) const
{
	return (_number);
}

void	Fixed::setRawBits(int const raw)
{
	_number = raw;
}

std::ostream&	operator<<(std::ostream& os, const Fixed& other)
{
	os << other.toFloat();
	return (os);
}
