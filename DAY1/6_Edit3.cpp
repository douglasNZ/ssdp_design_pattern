#include <iostream>
#include <string>
#include <conio.h>

// 변하는 것을 분리하는 2가지 방법
// 1. 변하는 것을 가상함수로 - template method
// 
// 2. 변하는 것을 다른 클래스로.. 
//    => 변해야 하므로 인터페이스 기반의 약한결합 사용

// 모든 Validator 는 아래 인터페이스를 구현해야 한다.
struct IValidator
{
	virtual bool validate(const std::string& data, char c) = 0;

	virtual bool iscomplete(const std::string& data) { return true; }
	
	virtual ~IValidator() { }
};

class Edit
{
	std::string data;
	//--------------------------------------------
	IValidator* pv = nullptr;
public:
	void setValidator(IValidator* p) { pv = p; }
	//--------------------------------------------

	std::string getData()
	{
		data.clear();

		while (1)
		{
			char c = _getch(); 

			if (c == 13 && (pv == nullptr || pv->iscomplete(data))  ) break;

			if ( pv == nullptr || pv->validate(data, c) ) // 값의 유효성여부를 외부 객체에 위임
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


