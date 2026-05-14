#include "Span.hpp"

Span::Span(void) : _maxSize(0)
{
}

Span::Span(unsigned int n) : _maxSize(n)
{
}

Span::Span(const Span &other) : _maxSize(other._maxSize), _numbers(other._numbers)
{
}

Span::~Span(void)
{
}

Span	&Span::operator=(const Span &other)
{
	if (this != &other)
	{
		_maxSize = other._maxSize;
		_numbers = other._numbers;
	}
	return *this;
}

void	Span::addNumber(int number)
{
	if (_numbers.size() >= _maxSize)
		throw FullException();
	_numbers.push_back(number);
}

unsigned int	Span::shortestSpan(void) const
{
	std::vector<int>	copy;
	unsigned int	shortest;

	if (_numbers.size() < 2)
		throw NoSpanException();
	copy = _numbers;
	std::sort(copy.begin(), copy.end());
	shortest = static_cast<unsigned int>(static_cast<long>(copy[1]) - copy[0]);
	for (std::vector<int>::size_type i = 2; i < copy.size(); ++i)
	{
		unsigned int current = static_cast<unsigned int>(static_cast<long>(copy[i]) - copy[i - 1]);

		if (current < shortest)
			shortest = current;
	}
	return shortest;
}

unsigned int	Span::longestSpan(void) const
{
	std::vector<int>::const_iterator	minimum;
	std::vector<int>::const_iterator	maximum;

	if (_numbers.size() < 2)
		throw NoSpanException();
	minimum = std::min_element(_numbers.begin(), _numbers.end());
	maximum = std::max_element(_numbers.begin(), _numbers.end());
	return static_cast<unsigned int>(static_cast<long>(*maximum) - *minimum);
}

const char	*Span::FullException::what(void) const throw()
{
	return "span is full";
}

const char	*Span::NoSpanException::what(void) const throw()
{
	return "not enough numbers to find a span";
}
