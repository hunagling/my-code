#ifndef MYSTACK_H_
#define MYSTACK_H_
using namespace std;
#include <iostream>
const int maxsize = 100;
class Stack {   //实现栈的结构
private:
	char* s;
	int top;

public:
	Stack()
	{
		s = new char[maxsize];
		top = 0;
	}
	bool isEmpty()
	{
		if (top == 0)
			return true;
		else
			return false;
	}
	bool isFull()
	{
		if (top > maxsize - 1)
			return true;
		else
			return false;
	}
	void push(char a)
	{
		if (isFull())
		{
			cout << "overflow!!" << endl;
			exit(1);
		}
		else
			s[top++] = a;
	}
	int pop()
	{
		return s[--top];
	}

};

#endif