#include <iostream>
#include <string>
#include <conio.h>

// �ٽ� 1. validation ��å��  ����ڰ� �����Ҽ� �־�� �Ѵ�.


class Edit
{
	std::string data;
public:

	// ���뼺�� �������� �и�
	// ������ ���� �ڵ峻�� ���ؾ� �ϴ� �κ��� �����Լ��� �и��Ѵ�.
	virtual bool validate(char c)
	{
		return true;
	}

	std::string getData()
	{
		data.clear();

		while (1)
		{
			char c = _getch(); 

			if (c == 13) break; 

			if (validate(c)) // validation ��å�� ������ �����Լ� ȣ��
			{
				data.push_back(c);
				std::cout << c;
			}
		}
		std::cout << std::endl;
		return data;
	}
};
// ���� Validation ��å�� �����Ϸ��� Edit �� �Ļ�Ŭ������ �����ؼ�
// validate �����Լ��� ������ �ϸ� �˴ϴ�.
// "���̺귯�� Ȯ��"�� ����
class NumEdit : public Edit
{
public:
	bool validate(char c) override
	{
		return isdigit(c);
	}
};

int main()
{
//	Edit e1;  // ��� ���� �Է�
	NumEdit e;// ���ڸ� �Է�
	while (1)
	{
		std::cout << e.getData() << std::endl;
	}
}


