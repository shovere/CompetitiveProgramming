
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


