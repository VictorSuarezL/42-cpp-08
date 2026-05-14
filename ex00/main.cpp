#include "easyfind.hpp"

int	main(void)
{
	std::vector<int> numbers;
	std::list<int> otherNumbers;

	numbers.push_back(4);
	numbers.push_back(8);
	numbers.push_back(15);
	numbers.push_back(16);
	numbers.push_back(23);
	numbers.push_back(42);

	otherNumbers.push_back(10);
	otherNumbers.push_back(20);
	otherNumbers.push_back(30);

	try
	{
		std::cout << "Found in vector: " << *easyfind(numbers, 15) << std::endl;
		std::cout << "Found in list: " << *easyfind(otherNumbers, 20) << std::endl;
		std::cout << "Searching 99..." << std::endl;
		std::cout << *easyfind(numbers, 99) << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}
