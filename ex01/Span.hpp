#ifndef SPAN_HPP
# define SPAN_HPP

# include <algorithm>
# include <cstdlib>
# include <exception>
# include <iostream>
# include <iterator>
# include <stdexcept>
# include <vector>

class Span
{
	private:
		unsigned int		_maxSize;
		std::vector<int>	_numbers;

	public:
		Span(void);
		Span(unsigned int n);
		Span(const Span &other);
		~Span(void);

		Span	&operator=(const Span &other);

		void			addNumber(int number);
		unsigned int	shortestSpan(void) const;
		unsigned int	longestSpan(void) const;

		template <typename InputIterator>
		void	addRange(InputIterator first, InputIterator last)
		{
			unsigned int count = static_cast<unsigned int>(std::distance(first, last));

			if (count > _maxSize - _numbers.size())
				throw std::out_of_range("span is full");
			_numbers.insert(_numbers.end(), first, last);
		}

		class FullException : public std::exception
		{
			public:
				virtual const char	*what(void) const throw();
		};

		class NoSpanException : public std::exception
		{
			public:
				virtual const char	*what(void) const throw();
		};
};

#endif
