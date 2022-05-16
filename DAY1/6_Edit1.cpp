#include <iostream>
#include <string>
#include <conio.h>

class Edit
{
	std::string data;
public:
	
	
	
	std::string getData()
	{
		data.clear();

		while (1)
		{
			char c = _getch(); // 한자 입력

			if (c == 13) break; // enter 입력시 무한 루프탈출

			if (isdigit(c))
			{
				data.push_back(c);
				std::cout << c;
			}
		}
		std::cout << std::endl;

		return data;
	}



};

int main()
{
	Edit e;
	while (1)
	{
		std::cout << e.getData() << std::endl;
	}
}


