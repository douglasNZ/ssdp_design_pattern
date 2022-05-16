#include <iostream>
#include <string>
#include <conio.h>

// 핵심 1. validation 정책은  사용자가 변경할수 있어야 한다.


class Edit
{
	std::string data;
public:

	// 공통성과 가변성의 분리
	// 변하지 않은 코드내의 변해야 하는 부분은 가상함수로 분리한다.
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

			if (validate(c)) // validation 정책은 별도의 가상함수 호출
			{
				data.push_back(c);
				std::cout << c;
			}
		}
		std::cout << std::endl;
		return data;
	}
};
// 이제 Validation 정책을 변경하려면 Edit 의 파생클래스를 설계해서
// validate 가상함수를 재정의 하면 됩니다.
// "라이브러리 확장"의 개념
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
//	Edit e1;  // 모든 문자 입력
	NumEdit e;// 숫자만 입력
	while (1)
	{
		std::cout << e.getData() << std::endl;
	}
}


