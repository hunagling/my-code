#ifndef MYSTACK_H_
#define MYSTACK_H_
#include<stdlib.h>

typedef struct stacknode
{
	int data;
	struct stacknode* next;
}stacknode, * LinkStack;
class Stack
{
public:

	//入栈函数
	LinkStack push(LinkStack& top, int value)
	{
		LinkStack p = new stacknode;
		if (p != NULL)
		{
			p->data = value;//可以理解为在链表尾部插入一个节点。
			p->next = top->next;
			top->next = p;
		}
		return top;
	}
	int pop(LinkStack& top)
	{
		LinkStack temp = new stacknode;
		int data;
		{
			temp = top->next;//可以理解为删除一个节点
			data = temp->data;
			top->next = temp->next;
			delete(temp);
		}
		return data;
	}
	//栈的初始化
	void Init(LinkStack& top)
	{
		top = new stacknode;
		top->next = NULL;
	}

};
#endif