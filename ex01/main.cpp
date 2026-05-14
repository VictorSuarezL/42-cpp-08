#include "Span.hpp"

int	main(void)
{
	Span sp(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	try
	{
		sp.addNumber(100);
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	Span big(10000);
	std::vector<int> values;
	for (int i = 0; i < 10000; ++i)
		values.push_back(i * 2);
	big.addRange(values.begin(), values.end());
	std::cout << big.shortestSpan() << std::endl;
	std::cout << big.longestSpan() << std::endl;

	try
	{
		Span tooSmall(1);
		tooSmall.addNumber(42);
		std::cout << tooSmall.shortestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}
