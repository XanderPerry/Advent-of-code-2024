#include <iostream>

int Day1(void);
int Day2(void);

int main(void)
{
	int day;

	std::cout << "What day do you want to run?" << std::endl;
	std::cin >> day;

	switch (day)
	{
	case 1:
		Day1();
		break;

	case 2:
		Day2();
		break;

	default:
		std::cout << "Incorrect input" << std::endl;
		break;
	}
}