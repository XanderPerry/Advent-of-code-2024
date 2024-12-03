#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

#define DEBUG_P1 false
#define DEBUG_P2 false

#define LINE_LEN 13
#define N_LINES 1000

int Day1(void)
{
	///////////////////////////////////////////////
	//
	//			PART 1
	//
	//////////////////////////////////////////////

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
		if (DEBUG_P1) { std::cout << "[" << i << "]	" << CurrentLine << std::endl; }

		//	Extract numbers as string
		std::string num1 = CurrentLine.substr(0, 5);
		std::string num2 = CurrentLine.substr(8, 11);
		if (DEBUG_P1) { std::cout << "num1: " << num1 << "	num2: " << num2 << std::endl; }

		//	Convert numbers to int and add to list
		List1[i] = stoi(num1);
		List2[i] = stoi(num2);
		if (DEBUG_P1) { std::cout << "List1: " << List1[i] << "	List2: " << List2[i] << std::endl; }

		if (DEBUG_P1) { std::cout << std::endl; }
	}
	file.close();
	
	//	Sort lists
	std::sort(std::begin(List1), std::end(List1));
	std::sort(std::begin(List2), std::end(List2));

	if (DEBUG_P1)
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
		if (DEBUG_P1)
		{
			std::cout << i << "	|" << List1[i] << " - " << List2[i] << "| = " << abs(List1[i] - List2[i]) << std::endl;
			std::cout << "Current distance: " << TotalDist << std::endl;
		}
	}
	
	std::cout << "The total distance is: " << TotalDist << std::endl;


	///////////////////////////////////////////////
	//
	//			PART 2
	//
	//////////////////////////////////////////////

	int similarity = 0;
	for (int i = 0; i < N_LINES; i++)
	{
		//	Count appearences of current item in List2
		int n_appearances = 0;
		for (int j = 0; j < N_LINES; j++)
			if (List1[i] == List2[j])
				n_appearances++;

		//	Calculate similarity
		similarity += List1[i] * n_appearances;

		if (DEBUG_P2) 
		{ 
			std::cout << List1[i] << " appears " << n_appearances << " times" << std::endl; 
			std::cout << List1[i] << " * " << n_appearances << " = " << List1[i] * n_appearances << std::endl;
			std::cout << "Current similarity is: " << similarity << std::endl;
			std::cout << std::endl;
		}
	}

	std::cout << "List similarity is: " << similarity << std::endl;

	return 0;
}

