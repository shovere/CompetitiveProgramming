//problem:  https://vjudge.net/problem/UVA-12289
//solution
#include <iostream>
#include <string>

int main()
{
	std::string words[3] = { "one", "two", "three" };
	int amount;
	std::string s;
	std::cin >> amount;


	while (std::getline(std::cin, s) && amount >= 0)
	{
		if (s.length() == 5)
		{
			std::cout << 3 << std::endl;
		}
		if (s.length() == 3)
		{
			int max = 1;
			for (int i =0; i < 3; i++)
			{
				if (s[i] != words[0][i])
					max--;
				if (max < 0)
					break;
				
			}
			if (max == 0 || max == 1)
			{
				std::cout << 1 << std::endl;
			}
			else
			{
				max = 1;
				for (int i = 0; i < 3; i++)
				{
					if (s[i] != words[1][i])
						max--;
					if (max < 0)
						break;
					
				}
				if (max == 0 || max == 1)
				{
					std::cout << 2 << std::endl;
				}
			}
		}
		amount--;
	}
	
}   
