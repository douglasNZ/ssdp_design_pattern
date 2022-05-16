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
		return data.size() < limit && isdigit(c);
	}

	bool iscomplete(const std::string& data) override
	{
		return data.size() == limit;
	}
};
// 4:55~ �� �̾����ϴ�.


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

	LimitDigitValidator v2(15);  // v�� �ϴ����� �߻����� ������.!!
	e.setValidator(&v2);


	while (1)
	{
		std::cout << e.getData() << std::endl;
	}
}
// ���ϴ� ���� �и��ϴ� 2���� ���
// 1. ���ϴ� ���� �����Լ��� - template method
// 2. ���ϴ� ���� �ٸ� Ŭ������ - strategy

// strategy : ����ð��� validatiorn ��ü ����
//            �ٸ� �Է� ���������� IValidator ��밡��..
// 
// template method : ����ð� ��ü �ȵǰ�, 
//					 NumEdit �� ��å�� �ٸ� �Էµ�����  ������


// ���������� ������ draw()/draw_imp() �� ���
// ����� �׸��� �׸��� ��å��
// 1. ����ð��� ����� �ʿ� ����,
// 2. �ٸ� Ŭ���������� ����� �ʿ� �����ϴ�.
// => template method�� �����ϴ�.(���������ڷ� ��ȣ ����, ��� ����Ÿ ���ٵ� ��)

// Edit/IValidator ��
// 1. Validation ��å�� ����ð� ���氡���ϸ� �����ϴ�.
// 2. Validation ��å�� Edit �� �ƴ϶� �ٸ� �Էµ����� �ʿ�
// => strategy�� �����ϴ�.















