/*
Problem description:
Luka is driving his truck along a long straight road with many traffic lights. For each traffic light he knows how long the red and green lights will be on (the cycle repeating endlessly).

When Luka starts his journey, all traffic lights are red and just started their cycle. Luka moves one distance unit per second. When a traffic light is red, he stops and waits until it turns green.

Write a program that determines how much time Luka needs to reach the end of the road. The start of the road is at distance zero, the end at distance L.

Input
The first line contains two integers N and L (1≤N≤100, 1≤L≤1000), the number of traffic lights on the road and the length of the road.

Each of the next N lines contains three integers D, R and G, describing one traffic light (1≤D<L, 1≤R≤100, 1≤G≤100). D is the distance of the traffic light from the start of the road. R and G denote how long the red and green lights are on, respectively.

The traffic lights will be ordered in increasing order of D. No two traffic lights will share the same position.

Output
Output the time (in seconds) Luka needs to reach the end of the road.

*/

//solution

#include <iostream>

int main()
{

    int totalTime = 0;
    int numLights = 0;
    int roadLength = 0;

    std::cin >> numLights;
    std::cin >> roadLength;

    int lastDist = 0;
    int currDist;
    int redTime;
    int greenTime;
    for (int j = 0; j < numLights ; ++j)
    {
            std::cin >> currDist;
            totalTime += (currDist - lastDist);
            std::cin >> redTime;
            std::cin >> greenTime;
            int t = totalTime % (greenTime + redTime);
            if (t < redTime )
                totalTime += redTime - t;
            lastDist = currDist;
    }

    totalTime += roadLength - lastDist;

    std::cout << totalTime;

}
