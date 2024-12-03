#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <sstream>

#define DEBUG_P1 true

int Day2(void)
{
	///////////////////////////////////////////////
	//
	//			PART 1
	//
	//////////////////////////////////////////////

	//	Open data file
	std::ifstream file("Day_2_input.txt");
	if (!file.is_open())
	{
		std::cerr << "File failed to open" << std::endl;
		return 1;
	}

	uint8_t	N_safe = 0;
	std::string CurrentLine;
	std::string token;

	while (std::getline(file, CurrentLine))
	{
		std::istringstream iss(CurrentLine);
		int last = stoi(std::getline(iss, token, ' '));

		while (std::getline(iss, token,  ' '))
		{
			if (DEBUG_P1) { std::cout << token << ' '; }
			

		}
		if (DEBUG_P1) { std::cout << '\n' << std::endl; }
	}

	file.close();

	return 0;
}