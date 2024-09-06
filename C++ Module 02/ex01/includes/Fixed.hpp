#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int					_number;
		static const int	_position = 8;
	public:
		Fixed(void);
		Fixed(const int n);
		Fixed(const float f);
		Fixed(const Fixed& other);
		~Fixed(void);
		Fixed& operator=(const Fixed& other);
		int		toInt(void) const;
		float	toFloat(void) const;
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

std::ostream&	operator<<(std::ostream& os, const Fixed& other);

#endif