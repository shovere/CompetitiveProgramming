//problem:  https://vjudge.net/problem/Kattis-cetvrta
//solution
#include <iostream>
#include <stack>

using namespace std;

void Stuff(int temp, stack<int>& xOne, stack<int>& xTwo)
{
    if(!xOne.empty())
    {
        if (temp == xOne.top())
            xOne.pop();
    }
    else
    {
        xTwo.push(temp);
        return;
    }

    if(!xTwo.empty())
    {
        if(temp == xTwo.top())
            xTwo.pop();
    }
    else
    {
        xOne.push(temp);
    }
}

int main()
{
    stack<int> xOne;
    stack<int> xTwo;
    stack<int> yOne;
    stack<int> yTwo;

    int temp = 0;

    cin >> temp;
    xOne.push(temp);
    cin >> temp;
    yOne.push(temp);

    cin>>temp;
    if(temp != xOne.top())
        xTwo.push(temp);
    else
        xOne.pop();

    cin >> temp;
    if(temp != yOne.top())
        yTwo.push(temp);
    else
        yOne.pop();

    cin >> temp;
    Stuff(temp, xOne, xTwo);
    cin >> temp;
    Stuff(temp, yOne, yTwo);

    if(!xTwo.empty())
        cout << xTwo.top();
    else if (!xOne.empty())
        cout << xOne.top();

    cout << " ";

    if(!yTwo.empty())
        cout << yTwo.top();
    else if (!yOne.empty())
        cout << yOne.top();

    return 0;

}
