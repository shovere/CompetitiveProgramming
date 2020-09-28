// ConsoleApplication21.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

struct cow
{
	int cowNum = 0;
	int start = 0;
	int end = 0;
	int stall = 0;
};


int main()
{
	int st = 0;
	cin >> st;
	vector<cow> barn(st);
	auto cmp = [](cow& a, cow& b){return a.end > b.end; };
	priority_queue < cow, std::vector<cow>, decltype(cmp)> stalls(cmp);

	for (int i=0; i < st; i++)
	{
		cow c;
		c.cowNum = i;
		cin >> c.start;
		cin >> c.end;
		barn[i] = c;
	}

	 sort(barn.begin(), barn.end(), [](cow& a, cow&b)->bool {return a.start < b.start; });

	 int numStalls = 0;
	for (int i = 0; i < barn.size(); i++)
	{
		if (stalls.empty() || barn[i].start < stalls.top().end)
		{
			
			numStalls++;
			barn[i].stall = numStalls;
			stalls.push(barn[i]);
		}
		else if(barn[i].start >= stalls.top().end)
		{
			barn[i].stall = stalls.top().stall;
			stalls.pop();
			stalls.push(barn[i]);
		}
		cout << barn[i].stall << '\n';
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
