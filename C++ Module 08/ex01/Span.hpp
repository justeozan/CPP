#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>

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

		void		addNumber(int n);

		template <typename T>
		void addRange(T first, T last)
		{
			for (; first != last; ++first)
				addNumber(*first);
		}
		unsigned int shortestSpan(void) const;
		unsigned int longestSpan(void) const;

		std::vector<int> getVector() const;

		class SpanException : public std::exception
		{
			public:
				const char *what() const throw();
		};		
};

std::ostream& operator<<(std::ostream os, const Span &span);

#endif  /* SPAN_HPP */