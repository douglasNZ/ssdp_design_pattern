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
			char c = _getch(); // ���� �Է�

			if (c == 13) break; // enter �Է½� ���� ����Ż��

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


