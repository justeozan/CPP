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

void Span::addRange(std::vector<int>::iterator first, std::vector<int>::iterator last) {
	if (last <= first)
		throw SpanException();
	if (_vector_int.size() + (last - first) > _size)
		throw SpanException();
	for (; first != last; first++) {
		if (_vector_int.size() == _size)
			throw SpanException();
		_vector_int.push_back(*first);
	}
}

void Span::getVector(void) const {
	if (_vector_int.empty())
		return;
	std::cout << "[ ";
	if (_vector_int.size() > 10) {
		for (size_t i = 0; i < 10; i++)
			std::cout << _vector_int[i] << " ";
		std::cout << " ... ";
		for (size_t i = _vector_int.size() - 10; i < _vector_int.size(); i++)
			std::cout << _vector_int[i] << " ";
		std::cout << "]" << std::endl;
		return;
	}
	for (size_t i = 0; i < _vector_int.size(); i++)
		std::cout << _vector_int[i] << " ";
	std::cout << "]" << std::endl;
}

const char *Span::SpanException::what() const throw() {
	return "Error: The Vector is full or range is invalid";
}
