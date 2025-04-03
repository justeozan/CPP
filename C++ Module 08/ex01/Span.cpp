#include "Span.hpp"

Span::Span() : _size(0) {}

Span::Span(unsigned int size) : _size(size) {}

Span::~Span() {}

Span &Span::operator=(const Span &src) {
	if (this != &src) {
		_size = src._size;
		_vector_int = src._vector_int;
	}
	return *this;
}

void Span::addNumber(int n) {
	if (_vector_int.size() == _size)
		throw SpanException();
	_vector_int.push_back(n);
}

unsigned int Span::shortestSpan(void) const {
	if (_vector_int.size() < 2)
		throw SpanException();
	std::vector<int> sorted = _vector_int;
	std::sort(sorted.begin(), sorted.end());

	unsigned int shortest = sorted[1] - sorted[0];
	for (unsigned int i = 2; i < sorted.size(); i++)
	{
		unsigned int current = static_cast<unsigned int>(sorted[i] - sorted[i - 1]);
		if (current < shortest)
			shortest = current;
	}
	return shortest;
}

unsigned int Span::longestSpan(void) const {
	if (_vector_int.size() < 2)
		throw SpanException();
	std::vector<int> sorted = _vector_int;
	std::sort(sorted.begin(), sorted.end());
	return sorted.back() - sorted.front();
}

std::vector<int> Span::getVector() const { return _vector_int; }

std::ostream& operator<<(std::ostream &os, const Span &span) {
	const std::vector<int> &vector = span.getVector();
	os << "[";
	for (size_t i = 0; i < vector.size(); i++) {
		os << vector[i];
		if (i != vector.size() - 1)
			os << ", ";
	}
	os << "]";
	return os;
}

const char *Span::SpanException::what() const throw() {
	return "Error: SpanException";
}
