#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

void method1(int p)
{
	cout << "method1(p): " << p << endl;
}
void method2(int p1, int p2)
{
	cout << "method2(p1+p2):" << p1 + p2 << endl;
}

void NoMutex(const char* name)
{
	for (int i = 1; i <= 5; i++)
	{
		cout << name << ":" << i << endl;
	}
}

void UsingMutex(const char* name)
{
	mutex _mtx;// mutex »ý¼º

	_mtx.lock();
	for (int i = 1; i <= 5; i++)
	{
		
		cout << name << ":" << i << endl;
	}
	_mtx.unlock();
}
int main()
{
	thread t1(method1, 5);
	thread t2(method2, 5, 5);
	t1.join();
	t2.join();
	cout << "--------------------" << endl;
	thread t3(NoMutex, "th3");
	thread t4(NoMutex, "th4");
	t3.join();
	t4.join();
	cout << "--------------------" << endl;

	thread t5(UsingMutex, "th5");
	thread t6(UsingMutex, "th6");

	t5.join();
	t6.join();
	return 0;
}