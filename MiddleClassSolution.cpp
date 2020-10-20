//problem:  https://vjudge.net/problem/CodeForces-1334B
//solution
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	 int numLines;
	 cin >> numLines;

	 for (int i = 0; i < numLines; i++)
	 {
		 int n;
		 int x;
		 

		 cin >> n;
		 cin >> x;

		 int* arr = new int[n];

		 for (int i =0; i < n; i++)
		 {
			 cin >> arr[i];
		 }

		 sort(arr, arr + n, greater<int>());
		 

		 int numWealthy = 1;

		 float total = 0;
		 float avg = 0;
		 for(int j = 0; j < n; j++)
		 {
			 total += arr[j];
			 avg = total / numWealthy;
			 if (avg < x)
			 {
				 cout << numWealthy - 1 << endl;
				 break;
			 }
			 numWealthy++;
		 }
		 
		 if (numWealthy -1 == n)
		 {
			 cout << numWealthy -1<< endl;
		 }
	 }
}
