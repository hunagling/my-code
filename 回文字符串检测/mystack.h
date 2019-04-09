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

	//��ջ����
	LinkStack push(LinkStack& top, int value)
	{
		LinkStack p = new stacknode;
		if (p != NULL)
		{
			p->data = value;//�������Ϊ������β������һ���ڵ㡣
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
			temp = top->next;//�������Ϊɾ��һ���ڵ�
			data = temp->data;
			top->next = temp->next;
			delete(temp);
		}
		return data;
	}
	//ջ�ĳ�ʼ��
	void Init(LinkStack& top)
	{
		top = new stacknode;
		top->next = NULL;
	}

};
#endif