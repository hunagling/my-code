// 回文字符串检测.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<string>
#include<stack>
using namespace std;
class strings
{
private:
	string str, b;
	char ss, v;
	stack<int> q;
	int flag;

public:
	void input()
	{
		cout << "Please_input_your_string:";
		cin >> str;

	}
	void check()
	{
		for (int i = 0; i < str.length(); i++)
		{			
			q.push(str[i]);
		}
		for (int i = 0; i < str.length(); i++)
		{
			b[i] = q.top();
			q.pop();
		}
		int i = 0;
		while (i < str.length() / 2)
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

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
