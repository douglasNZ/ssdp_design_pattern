#include <iostream>

// ���� ����(looselty coupling)
// �ϳ��� Ŭ������ �ٸ� Ŭ���� ����
// ��Ģ�� ���� �������̽�(�߻�Ŭ����)�� ���ؼ� ����ϴ� ��

// Ȯ�强 �ִ� ������ ������
// OCP�� �����ϴ� ������


// ���� ���̽� : ���Ѿ� �ϴ� ��Ģ(���������Լ�)�� �ִ� ��� 
// �߻� Ŭ���� : ���Ѿ� �ϴ� ��Ģ(���������Լ�) + �ٸ� ����鵵 �ִ� ���






// ī�޶� ���� ������ ���� ī�޶�� ����ڰ��� ���Ѿ� �ϴ� ��Ģ�� ���� �����Ѵ�.

// ��Ģ : ��� ī�޶�� �Ʒ� Ŭ������ ���� �Ļ��Ǿ�� �Ѵ�.
//      => �ǵ� : ��� ī�޶󿡴� "Take()" ��� �̸��� �Լ� �� �־���Ѵ�.
class ICamera
{
public:
	virtual void Take() = 0;
};

// ���� ī�޶�� ���� ������, ��Ģ�� �ִ�.
// ī�޶� ����ڴ� ��Ģ ��θ� ����ϸ� �ȴ�.
class People
{
public:
	void UseCamera(ICamera* p) { p->Take(); }
};

// ����, ��� ī�޶�� ��Ģ��� ������ �մϴ�.
// ��Ģ : ICamera�� ���� �Ļ��Ǿ�� �Ѵ�.
class Camera : public ICamera
{
public:
	void Take() { std::cout << "Take Picture" << std::endl; }
};

class HDCamera : public ICamera
{
public:
	void Take() { std::cout << "Take HD Picture" << std::endl; }
};

class UHDCamera : public ICamera
{
public:
	void Take() { std::cout << "Take UHD Picture" << std::endl; }
};

int main()
{
	People p;
	Camera c;
	p.UseCamera(&c);

	HDCamera hdc;
	p.UseCamera(&hdc); 

	UHDCamera uhdc;
	p.UseCamera(&uhdc); 
}





