#include<iostream>
using namespace std;

class CPU
{
public:
	virtual void calculate() = 0;
};
class Videocard
{
public:
	virtual void display() = 0;
};
class Memory
{
public:
	virtual void store() = 0;
};

class Intel_cpu :public CPU
{
public:
	void calculate()
	{
		cout << "this is Intel's CPU" << endl;
	}
};
class Intel_Videocard :public Videocard
{
public:
	void display()
	{
		cout << "this is Intel's Videocard" << endl;
	}
};
class Intel_Memory :public Memory
{
public:
	void store()
	{
		cout << "this is Intel's Memory" << endl;
	}
};

class Computer
{
public:
	Computer(CPU* cpu, Videocard* card, Memory* memory)
	{
		cout << "Computer的构造函数调用" << endl;
		m_cpu = cpu;
		m_card = card;
		m_memory = memory;
	}
	void work()
	{
		m_cpu->calculate();
		m_card->display();
		m_memory->store();
	}
	~Computer()
	{
		cout << "Computer的析构函数调用" << endl;
		if (m_cpu != NULL)
		{
			delete m_cpu;
			m_cpu = NULL;
		}
		if (m_card != NULL)
		{
			delete m_card;
			m_card = NULL;
		}
		if (m_memory != NULL)
		{
			delete m_memory;
			m_memory = NULL;
		}
	}

	CPU* m_cpu;
	Videocard* m_card;
	Memory* m_memory;
};
void test01()
{
	CPU* mycpu = new Intel_cpu;	//父类指针指向子类对象
	Videocard* mycard = new Intel_Videocard;
	Memory* mymemory = new Intel_Memory;

	Computer* mycom = new Computer(mycpu,mycard,mymemory);
	mycom->work();
	delete mycom;
}

int main()
{
	test01();
	return 0;
}