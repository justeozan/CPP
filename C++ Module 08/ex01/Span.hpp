#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>

#define RED "\033[31m"
#define RESET "\033[0m"

class Span
{
	private:
		unsigned int		_size;
		std::vector<int>	_vector_int;

	public:
		Span();
		Span(unsigned int size);
		~Span();
		Span(const Span &);
		Span &operator=(const Span &);

		void			addNumber(int n);
		void			addRange(std::vector<int>::iterator first, std::vector<int>::iterator last);
		void			getVector(void) const;
		unsigned int	shortestSpan(void) const;
		unsigned int	longestSpan(void) const;

		class SpanException : public std::exception {
			public:
				const char *what() const throw();
		};
};

#endif  /* SPAN_HPP */