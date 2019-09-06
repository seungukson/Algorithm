#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

int Count = 0;
void countProc1(int no);
void countProc2(int no);
int turn = 1;//turn ������ ����Ͽ� �ΰ��� �����忡 ������ �ο��ϱ�.

void countProc1(int no) {

	//while (turn != 1)
	//	std::this_thread::sleep_for(0s);

	int count;
	for (int i = 0; i < 10; i++) {
		count = Count;
		std::cout << "Thread#" << no << " : " << ++count << endl; //10���� �����尡 ������ ī��Ʈ�� ���� ����� ����Ѵ�
		Count = count;
		std::this_thread::sleep_for(std::chrono::duration<int>(1)); //�۵����� �����带 ��� sleep���·� ����ϰ� �ϴ� �ż���
	}

	turn = 2; // ������ ������ turn�� 2�� �������ش�.
}

void countProc2(int no) {

	//while (turn != 2)
	//	std::this_thread::sleep_for(0s);

	int count;
	for (int i = 0; i < 10; i++) {
		count = Count;
		std::cout << "Thread#" << no << " : " << ++count << endl;
		Count = count;
		std::this_thread::sleep_for(std::chrono::duration<int>(1));
	}

	turn = 1; //������ ������ turn�� �ٽ� �������ݴϴ�.
}

int main() {
	std::thread thread1(countProc1, 1); //10����ī��Ʈ�� ���� ������1
	std::thread thread2(countProc2, 2); //10���� ī��带 ���� ������2
	thread1.join(); //�ڽ� ��������� �����⸦ ��ٷȴٰ� �շ�(join)�ϱ� ���� �θ����μ������� ����ϴ� �ż���
	thread2.join(); //�ν����带 ���Ľ���.
	cout << "Count Result:" << Count << endl; //��� ���
	return 0;
}

