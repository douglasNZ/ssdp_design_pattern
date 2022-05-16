class Base
{
public:
	virtual void foo() {}
	virtual void goo(int) {}
};
class Derived1 : public Base
{
public:
	// �����Լ� �����ǽ� �Ǽ�(��Ÿ)�� �߻��߽��ϴ�.
	// => ������ �ƴ϶�, �����Ϸ��� ���ο� �����Լ��� �߰��ߴٰ� �����ϰԵ˴ϴ�.
	// => ������ ����..
	virtual void fooo() {}
	virtual void goo(double){}
};
class Derived2 : public Base
{
public:
	// C++11 ����. �� ������ �ذ��ϱ� ���� "override" Ű���尡 ���ԵǾ����ϴ�.
	// => �ش� �Լ��� ��� Ŭ������ ���� ��� "������ ����"
//	virtual void fooo() override {}
//	virtual void goo(double)  override {}

	void foo()    override {}
	void goo(int) override {}
};

int main()
{
	Base* p = new Derived1;
	p->foo();
}





