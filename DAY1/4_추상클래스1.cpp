// 1_�߻�Ŭ����1.cpp - 10page
// 
// �߻�Ŭ���� : ���� �����Լ��� �Ѱ� �̻� �ִ� Ŭ����
// Ư¡      : ��ü�� ����� ����.
// �ǵ�      : Ư����(��ӵ�) �Լ��� �ݵ�� ������ �Ѵٰ� �����ϴ� �� 
class Shape
{
public:
	virtual void Draw() = 0; // ���� �����Լ�(pure virtual function)
							 // Ư¡ : ������ ����, =0 ���� ǥ�� 
};
class Rect : public Shape
{
	// Draw()�� �����θ� ������ ������ ���� �߻� Ŭ�����̴�.
public:
	void Draw() override {}
};

int main()
{
//	Shape  s; // error
	Shape* p; // ok. 
	Rect  r;  // ok.
}
