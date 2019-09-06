#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

int Count = 0;
void countProc1(int no);
void countProc2(int no);
int turn = 1;//turn 변수를 사용하여 두개의 스레드에 순서를 부여하기.

void countProc1(int no) {

	//while (turn != 1)
	//	std::this_thread::sleep_for(0s);

	int count;
	for (int i = 0; i < 10; i++) {
		count = Count;
		std::cout << "Thread#" << no << " : " << ++count << endl; //10까지 스레드가 번갈아 카운트를 세며 결과를 출력한다
		Count = count;
		std::this_thread::sleep_for(std::chrono::duration<int>(1)); //작동중인 스레드를 잠시 sleep상태로 대기하게 하는 매서드
	}

	turn = 2; // 실행이 끝나면 turn을 2로 변경해준다.
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

	turn = 1; //실행이 끝나면 turn을 다시 변경해줍니다.
}

int main() {
	std::thread thread1(countProc1, 1); //10까지카운트를 세는 스레드1
	std::thread thread2(countProc2, 2); //10까지 카운드를 세는 스레드2
	thread1.join(); //자식 스레드들이 끝나기를 기다렸다가 합류(join)하기 위해 부모프로세스에서 사용하는 매서드
	thread2.join(); //두스레드를 병렬실행.
	cout << "Count Result:" << Count << endl; //결과 출력
	return 0;
}

