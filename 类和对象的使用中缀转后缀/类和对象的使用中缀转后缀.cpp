// 类和对象的使用中缀转后缀.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include <iostream>
#include<string>
#include"mystack.h"
using namespace std;
Stack x;
class charge {

private:
	string str;
	char b[100];
	char c[100];
	
public:
	int check(int flag) {	//检测表达式是否正确，并初始化栈	
		//标志位，判断是否合法
		cout << "Please_input_your_expression:" << endl;
		cin >> str;
			for (int i = 0; i <str.length(); i++)
			{
				if ((str[i] >= '1' && '9' >= str[i]) || str[i] == '*' || str[i] == '+' || str[i] == '-' || str[i] == '/' || str[i] == '(' || str[i] == ')')
				{
					flag = flag;
				}
				else{
					flag = flag + 1;					
			      }
				if (str[i] == '*' || str[i] == '+' || str[i] == '-' || str[i] == '/' ) {//检测不能两个操作符连在一起
					if (str[i + 1] == '*' || str[i + 1] == '+' || str[i + 1] == '-' || str[i + 1] == '/') {
						flag = flag + 1;						
					}						
				}
				if (str[i] == '(') {//检测有左括号必须有右括号；
					int p = 0;//标志位检测后面是否有）
					for (i; i < (int)str.length(); i++) {
						if (str[i] == ')') {
							p=p+1;
						}
						if (str[i] != ')') {
							p = p;
						}
						
					}
					if (p == 1) { flag = flag;  }
					if (p == 0) { flag = flag+1; }

				}
			}
			if (flag == 0) {
				cout << "Expression_corrent"<<endl;
			}
			if (flag != 0)
			{
				cout << "Expression_error" << endl;
			}
			cout <<"flag:"<< flag<<endl;
			return flag;
			
	}
	void output() {
		int y= 0;//表示栈中个数
		for (int i = 0; i < (int)str.length(); i++) {
			if (str[i] >= '1' && '9' >= str[i]) {
				cout << str[i];
			}
			if (str[i] <= '1' && '9' >= str[i]){
				cout << ' ';
			}
			if(str[i]==')'){//遇到右括号的情况
				int q = 0;
				while (((b[q]=x.pop())!='(')&& !x.isEmpty()) {
					y = y - 1;
					cout << b[q] ;
					q=q+1;
				}
				y = y - 1;
			}
			if (str[i] == '*' ||  str[i] == '/' || str[i] == '(') {//直接入栈
				x.push(str[i]);				
				y = y + 1;
			}
			if (str[i] == '+' || str[i] == '-') {//传入+-符号需要判断前面是否有*/符号，满足优先级关系。
				if (!x.isEmpty()) {//栈非空，弹出栈顶进行比较
					int tmp;
					tmp = x.pop();
					if (tmp == '*' || tmp == '/') {//判断优先级。并且出栈
						cout << (char)tmp;
						for (int i = 0; i < y-1; i++) {
							c[i] = x.pop();
							cout << c[i];
						}
						x.push(str[i]);
						y = 1;
					}
					if (tmp == '+' || tmp == '-' || tmp == '(') {
						x.push(tmp);
						x.push(str[i]);
						y = y + 1;
					}
				}
				if (x.isEmpty()) {//栈空，那么-+操作符入栈
					x.push(str[i]);
					y = y + 1;
				}

				
			}


			
			
		}
		for (int i = 0; i < y; i++) {
			if (!x.isEmpty()) {
				b[i] = x.pop();
				cout << b[i];
			}
		}
	}
};
charge charge1;
int main()
{
	int flag=0;//标志位，判断是否合法
	string str;
	int p=charge1.check(flag);
	if (p == 0) {
		charge1.output();
	}
}


