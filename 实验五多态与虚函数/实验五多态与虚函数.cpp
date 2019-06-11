// 实验五多态与虚函数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
#include <iostream>
using namespace std;
template <class T>///声明一个模板，虚拟类型名为T
class Queue {
public:
	virtual int size() = 0;
	virtual bool isEmpty() = 0;
	virtual void print() = 0;
	//入队操作
	virtual void enqueue(T num) = 0;//传入一个虚拟类型的num
	//出队操作
	virtual void dequeue() = 0;
	//获得队首元素
	virtual T front() = 0;
};
template <class T>
class ArrayQueue:public Queue<int> {
protected:
	int  maxsize = 10;
	T* s;
	int rear;
	int fronts;//定义指针
public:

		ArrayQueue() {//构造函数
			s = new T[maxsize];
			rear = 0;
			fronts = 0;
		}
		~ArrayQueue()//析构函数
		{
			if (s) {
				delete[] s;
			}
		}

		int size() {
			cout <<"size:"<<rear - fronts<<endl;
			return rear - fronts;
		}
		bool isEmpty() {
			if (rear == fronts)
				return true;
			else
				return false;
		}
		void print() {
			cout << "ArrayQueue: ";
			size();
			cout << "front[";
			int i = fronts;
			for (i; i< rear; i++) {
				cout <<s[i]<<"," ;		
			}
			cout << "]rear" << endl;
		}
		//入队操作
	    virtual	void enqueue(T num) {		
				s[rear++] = num;
		}
		//出队操作
		void dequeue() {
			cout << s[fronts] << endl;
			fronts++;
		}
		//获得队首元素
		T front() {
			if (isEmpty())
				cout << "empty" << endl;
			else
				cout << s[fronts] << endl;
			return s[fronts];
		}
};

ArrayQueue<int> Queue1;
int main(){
	cout << "********************数组队列***************" << endl;;
	int a = 52;
	int b = 42;
	Queue1.enqueue(a);
	Queue1.enqueue(b);
	Queue1.enqueue(10000);
	Queue1.size();
	Queue1.print();

  
}

