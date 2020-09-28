//coloring socks, vjudge
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int s = 0;
	int c = 0;
	int k = 0;
	cin >> s;
	cin >> c;
	cin >> k;

	vector<int> socks(s);

	for (int i=0; i < s; i++)
	{
		cin >> socks[i];
	}

	sort(socks.begin(), socks.end());

	int start = socks[0];
	int numSocks = 1;
	int numMachines = 1;

	for (int i = 1; i < s; i++)
	{

		if (numSocks >= c || socks[i]-start > k)
		{
			numMachines++;
			start = socks[i];
			numSocks = 1;
		}
		else if (socks[i] - start <= k)
		{
			numSocks++;
		}
	}

	cout << numMachines << '\n';
}
