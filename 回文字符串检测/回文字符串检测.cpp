// 回文字符串检测.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include<iostream>
#include"mystack.h"
using namespace std;
	//出栈函数
Stack x;
class strings
{
private:
	int max = 100;
	int add = 20;
	string str;
	char ss, v;
	LinkStack s;
	int flag;
public:
	void input()
	{
		cout << "Please_input_your_string:";
		cin >> str;
	}
	void check()
	{
		x.Init(s);
		if (20 > (int)str.length())
			cout << "小于20"<<endl;
		else
			cout << "大于20"<<endl;
		while (max < (int)str.length())
		{
			max= max+add;
		}
		int *b=new int[max];
		for (int i = 0; i < (int)str.length(); i++)
		{			
			x.push(s,str[i]);
		}
		for (int i = 0; i < (int)str.length(); i++)
		{
		 b[i]=x.pop(s);			
		}
		int i = 0;
		while (i <(int)str.length()/2)
		{

			if ((int)str[i] > 0)
			{
				if (str[i] == b[i])
				{
					flag = 0;
				}
				else
				{
					flag = 1;
				}
				i++;
			}
			else
			{
				ss = str[i] + str[i + 1];
				v = b[i + 1] + b[i];
				if (ss == v)
				{
					flag = 0;
				}
				else flag = 1;

				i = i + 2;
			}
		}
   	  	if (flag == 0)
			cout << "yes";
		else
			cout << "no";
	}
};
class strings string1, string2;
int main()
{
	string1.input();
	string1.check();

}
