#include <iostream>
#include <string>
#include <conio.h>

struct IValidator
{
	virtual bool validate(const std::string& data, char c) = 0;
	virtual bool iscomplete(const std::string& data) { return true; }
	virtual ~IValidator() { }
};

// ���� �پ��� ��å�� ���� validator�� ���� �����ϸ� �˴ϴ�.

class LimitDigitValidator : public IValidator
{
	int limit;
public:
	LimitDigitValidator(int n) : limit(n) {}

	bool validate(const std::string& data, char c) override
	{
		return data.size() <= limit && isdigit(c);
	}
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

			if (c == 13 && (pv == nullptr || pv->iscomplete(data))) break;

			if (pv == nullptr || pv->validate(data, c)) // ���� ��ȿ�����θ� �ܺ� ��ü�� ����
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
	LimitDigitValidator v(5);  // v�� �ϴ����� �߻����� ������.!!
	e.setValidator(&v);

	while (1)
	{
		std::cout << e.getData() << std::endl;
	}
}


