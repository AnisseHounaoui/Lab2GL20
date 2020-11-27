#include <iostream>
#include <cstring>
#include <string>

void solve(std::string text)
{
	bool occured[0x100];
	memset(occured, false, sizeof(occured));

	std::string answer = "";
	for (auto c : text)
	{
		if (!occured[c]) occured[c] = true;
		else
		{
			answer = c;
			break;
		}
	}
	std::cout << ((answer != "") ? answer : "NULL") << std::endl;
}