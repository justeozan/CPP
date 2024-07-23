#include "../includes/Fixed.hpp"

Fixed::Fixed(void): _number(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int n)
{
	std::cout << "Int constructor called" << std::endl;
	_number = n << _position;
}

Fixed::Fixed(const float f)
{
	std::cout << "Float constructor called" << std::endl;
	_number = (int)roundf(f * (1 << _position));
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		_number = other.getRawBits();
	return (*this);
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
