#include <iostream>
#include <string>
#include <conio.h>

struct IValidator
{
	virtual bool validate(const std::string& data, char c) = 0;
	virtual bool iscomplete(const std::string& data) { return true; }
	virtual ~IValidator() { }
};

// 이제 다양한 정책을 가진 validator를 만들어서 제공하면 됩니다.

class LimitDigitValidator : public IValidator
{
	int limit;
public:
	LimitDigitValidator(int n) : limit(n) {}

	bool validate(const std::string& data, char c) override
	{
		return data.size() < limit && isdigit(c);
	}

	bool iscomplete(const std::string& data) override
	{
		return data.size() == limit;
	}
};
// 4:55~ 에 이어집니다.


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

			if (c == 13 && (pv == nullptr || pv->iscomplete(data))) break;

			if (pv == nullptr || pv->validate(data, c)) // 값의 유효성여부를 외부 객체에 위임
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
	LimitDigitValidator v(5);  // v가 하는일을 잘생각해 보세요.!!
	e.setValidator(&v);

	LimitDigitValidator v2(15);  // v가 하는일을 잘생각해 보세요.!!
	e.setValidator(&v2);


	while (1)
	{
		std::cout << e.getData() << std::endl;
	}
}
// 변하는 것을 분리하는 2가지 기술
// 1. 변하는 것을 가상함수로 - template method
// 2. 변하는 것을 다른 클래스로 - strategy

// strategy : 실행시간에 validatiorn 교체 가능
//            다른 입력 도구에서도 IValidator 사용가능..
// 
// template method : 실행시간 교체 안되고, 
//					 NumEdit 의 정책을 다른 입력도구는  사용못함


// 도형편집기 예제의 draw()/draw_imp() 의 경우
// 사격형 그림을 그리는 정책은
// 1. 실행시간에 변경될 필요 없고,
// 2. 다른 클래스에서도 사용할 필요 없습니다.
// => template method가 좋습니다.(접근지정자로 보호 가능, 멤버 데이타 접근도 편리)

// Edit/IValidator 는
// 1. Validation 정책은 실행시간 변경가능하면 좋습니다.
// 2. Validation 정책은 Edit 뿐 아니라 다른 입력도구도 필요
// => strategy가 좋습니다.















