/*
Problem:
Map websites such as Bing Maps and Google Maps often store their maps as many different image files, called tiles. 
The lowest zoom level (level 0) consists of a single tile with a low-detail image of the whole map, zoom level 1 
consists of four tiles each containing a slightly more detailed version of a quarter of the map, 
and in general zoom level n contains 4n different tiles that each contain a part of the map.

One way of identifying a tile is by means of a quadkey. A quadkey is a string of digits uniquely identifying a tile at a certain zoom level. 
The first digit specifies in which of the four quadrants of the whole map the tile lies: 0 for the top-left quadrant, 
1 for the top-right quadrant, 2 for the bottom-left quadrant and 3 for the bottom-right quadrant. 
The subsequent digits specify in which sub quadrant of the current quadrant the tile is. The quadkeys for zoom levels 1 to 3 are shown in Figure 1(a).

Another way of identifying a tile is to give the zoom level and x and y coordinates, where (0,0) is the left-top corner. 
The coordinates for the tiles of zoom level 3 are shown in Figure 1(b). Given the quadkey of a tile, output the zoom level and x and y coordinates of that tile.

The input consists of:

one line with a string s (1≤length(s)≤30), the quadkey of the map tile.

The string s consists of only the digits ‘0’, ‘1’, ‘2’ and ‘3’.

Output
Output three integers, the zoom level and the x and y coordinates of the tile.
*/


//solution
#include <iostream>


struct coordinates
{
    int MAX;
    int MIN = 0;
};

int exponentiate(int base, int exponent)
{
    int sum = 1;
    for (int i = 0; i < exponent; ++i)
    {
        sum = base*sum;
    }

    return sum;
}

int main()
{
    std::string s;
    std::cin >> s;

    coordinates exe;
    coordinates why;
    exe.MAX = exponentiate(2, s.length());
    why.MAX = exe.MAX;

    for (int i = 0; i < s.length(); ++i)
    {
        char c = s.at(i);
        switch(c)
        {
            case '0':
                exe.MAX = ((exe.MAX + exe.MIN)/2);
                why.MAX = ((why.MAX + why.MIN)/2);
                break;
            case '1':
                exe.MIN = ((exe.MAX + exe.MIN)/2);
                why.MAX = ((why.MAX + why.MIN)/2);
                break;
            case '2':
                exe.MAX = ((exe.MAX + exe.MIN)/2);
                why.MIN = ((why.MAX + why.MIN)/2);
                break;
            case '3':
                exe.MIN = ((exe.MAX + exe.MIN)/2);
                why.MIN = ((why.MAX + why.MIN)/2);
                break;

        }
    }
    exe.MIN;
    why.MIN;

    std::cout << s.length() << " " << exe.MIN << " "<< why.MIN << " " << std::endl;

    return 0;
}
