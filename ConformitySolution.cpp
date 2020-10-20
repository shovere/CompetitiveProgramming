//problem: https://vjudge.net/problem/Kattis-conformity
//solution
#include <iostream>
#include <set>
#include <map>
using namespace std;

int main()
{
	int numStudents = 0;
	map<set<int>, int> m;
	cin >> numStudents;

	for (int i = 0; i < numStudents; i++)
	{
		set<int> temp;
		for (int j = 0; j < 5; j++)
		{
			int q;
			cin >> q;
			temp.insert(q);
		}
		if (m.find(temp) == m.end())
		{
			m[temp] = 1;
		}
		else
		{
			m[temp]++;
		}
	}
	int weight = 0;
	int output = 0;
	for (auto it = m.begin(); it != m.end(); it++)
	{
		if (it->second > weight)
		{
			weight = it->second;
			output = weight;
		}
		else if (it->second == weight)
		{
			output += it->second;
		}
	}
	cout << output << endl;

	
}
