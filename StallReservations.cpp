//take in all the input, sort the cows by their starting milk time
//using a minheap (min end milk time priority queue) we can compare each first value in the sorted array of cows
//to the minimum time the last cow will complete her milking session
//this frees up a stall, so we do not need to add another, we simply set the value of the cow's stall to the minheap's top cow's stall value
//if the start time of a cow is less than the minheap top we increment the number of stalls and set the cow's stall value to this
//for both instances of cow stall setting we push the cow onto the minheap
//we then put the cow's stall in the proper position to output later, after we have outputted the number of stalls
//accepted
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

struct cow
{
    int cowNum;
    int start;
    int end;
    int stall;

    bool operator < (cow& a) const
    {
        return this->start < a.start;
    }
};

struct CustomCompare
{
    bool operator()(const cow& a, const cow& b)
    {
        return a.end > b.end;
    }
};

int main()
{
    int st = 0;
    cin >> st;
    vector<cow> barn(st);
    priority_queue < cow, std::vector<cow>,CustomCompare> stalls;

    for (int i = 0; i < st; i++)
    {
        cow c;
        c.cowNum = i;
        cin >> c.start;
        cin >> c.end;
        barn[i] = c;
    }

    vector<int> temp(st);

    sort(barn.begin(), barn.end());

    int numStalls = 0;
    for (int i = 0; i < barn.size(); i++)
    {
        if (stalls.empty() || barn[i].start <= stalls.top().end)
        {

            numStalls++;
            barn[i].stall = numStalls;
            stalls.push(barn[i]);
        }
        else if (barn[i].start > stalls.top().end)
        {
            barn[i].stall = stalls.top().stall;
            stalls.pop();
            stalls.push(barn[i]);
        }
        temp[barn[i].cowNum] = barn[i].stall;
    }

    cout << numStalls;
    for (int i=0; i < st; i++)
    {
        cout <<'\n' << temp[i];
    }
    return 0;
}
