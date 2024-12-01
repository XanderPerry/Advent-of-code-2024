#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

#define DEBUG false

#define LINE_LEN 13
#define N_LINES 1000

int main()
{
	//	Open data file
	std::ifstream file("Day_1_list.txt");
	if (!file.is_open())
	{
		std::cerr << "File failed to open" << std::endl;
		return 1;
	}



	//	Convert txt to list
	int List1[N_LINES], List2[N_LINES];
	std::string CurrentLine;
	for(int i = 0; std::getline(file, CurrentLine); i++)
	{
		if (DEBUG) { std::cout << "[" << i << "]	" << CurrentLine << std::endl; }

		//	Extract numbers as string
		std::string num1 = CurrentLine.substr(0, 5);
		std::string num2 = CurrentLine.substr(8, 11);
		if (DEBUG) { std::cout << "num1: " << num1 << "	num2: " << num2 << std::endl; }

		//	Convert numbers to int and add to list
		List1[i] = stoi(num1);
		List2[i] = stoi(num2);
		if (DEBUG) { std::cout << "List1: " << List1[i] << "	List2: " << List2[i] << std::endl; }

		if (DEBUG) { std::cout << std::endl; }
	}
	
	//	Sort lists
	std::sort(std::begin(List1), std::end(List1));
	std::sort(std::begin(List2), std::end(List2));

	if (DEBUG)
	{
		std::cout << "First elements of sorted lists:" << std::endl;
		for (int i = 0; i < 10; i++)
			std::cout << "List1: " << List1[i] << "	List2: " << List2[i] << std::endl;
	}

	//	Get total distance
	int TotalDist = 0;
	for (int i = 0; i < N_LINES; i++)
	{
		TotalDist += abs(List1[i] - List2[i]);
		if (DEBUG)
		{
			std::cout << i << "	|" << List1[i] << " - " << List2[i] << "| = " << abs(List1[i] - List2[i]) << std::endl;
			std::cout << "Current distance: " << TotalDist << std::endl;
		}
	}
	
	std::cout << "The total distance is: " << TotalDist << std::endl;

	file.close();
	return 0;
}

