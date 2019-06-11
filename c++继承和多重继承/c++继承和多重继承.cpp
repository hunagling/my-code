// c++继承和多重继承.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;

class Vehicle {
protected:
	int maxSpeed;
	int weight;
public:
	~Vehicle() {}//析构函数
	Vehicle(int m,int w) {//构造函数
		maxSpeed = m;
		weight = w;
	}
virtual	void run() {
		cout << "Vehicle Run" << endl;
	}
virtual	void stop(){
		cout << "Vehicle Stop" << endl;
	}
};
class bicycle : virtual public Vehicle {
protected:
	int height;
public:
	~bicycle(){}
	bicycle(int m,int w,int h):Vehicle(m, w) {	
		height = h;
	}
	void run() {
		cout << "bicycle Run" << endl;
	}
	void stop() {
		cout << "bicycle stop" << endl;
	}

};
class MotoCar : virtual public Vehicle {
protected:
	int seatNum;
public:
	~MotoCar(){}
	MotoCar(int m,int w,int s) :Vehicle(m, w) {
		seatNum = s;
	}
     void run() {
		cout << "MotoCar Run" << endl;
	}
     void stop() {
		cout << "MotoCar stop" << endl;
	}

};

class motorcycle: public bicycle,public MotoCar {
public:
	~motorcycle(){}
	motorcycle(int m,int w,int h,int s):Vehicle(m, w), bicycle(m, w, h), MotoCar(m, w, s){}
	void run() {
		cout << "motorcycle Run" << endl;
	}
	void stop() {
		cout << "motorcycle stop" << endl;
	}

};

int main()
{
	Vehicle a(12, 15);
	bicycle b(15,16,15);
	MotoCar c(45,56,99);
	motorcycle d(88, 55, 44, 66);
	Vehicle* p[4] = { &a,&b,&c,&d };
	for (int i = 0; i < 4; i++) {
		p[i]->stop();
		p[i]->run();
	}
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
