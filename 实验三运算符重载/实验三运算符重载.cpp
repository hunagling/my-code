 // 实验三运算符重载.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<string>
#include<math.h>
using namespace std;
class Complex
{
public :
	Complex() {  real = 0,imag = 0; }//定义构造函数
	Complex(float r, float i) { real = r; imag = i; }//构造函数重载
	friend Complex operator * (Complex& c1, Complex& c2);//重载乘法 为Comolex的友元类
	friend Complex operator / (Complex& c1, Complex& c2);//重载除法 
	friend Complex operator + (Complex& c1, Complex& c2);//重载加法 
	friend Complex operator - (Complex& c1, Complex& c2);//重载减法 
	void display();

private:
	float real;
	float imag;
};
Complex operator * (Complex& c1, Complex& c2)//具体重载函数
{
	return Complex(c1.real * c2.real - c1.imag * c2.imag, c1.real * c2.imag + c1.imag * c2.real);
}
Complex operator / (Complex & c1, Complex & c2)
{
	Complex c;
	c.real = (c1.real * c2.real + c1.imag * c2.imag) / (c2.real * c2.real + c2.imag * c2.imag);
	c.imag = (c1.imag * c2.real - c1.real * c2.imag) / (c2.real * c2.real + c2.imag * c2.imag);
	return Complex(c.real,c.imag);
}
Complex  operator + (Complex & c1, Complex & c2)
{
	return Complex(c1.real + c2.real, c1.imag + c2.imag);
}
Complex  operator - (Complex & c1, Complex & c2)
{
	return Complex(c1.real - c2.real, c1.imag - c2.imag);
}
void Complex::display() {
	cout << "(" << real << "," << imag << "i)" << endl;
}


int check(int flag,char*str) {	//检测表达式是否正确，并初始化栈	
	for (int i = 0; i <strlen(str); i++)
	{//不能有非法字符
		if ((str[i] >= '0' && '9' >= str[i]) || str[i] == '*' || str[i] == '+' || str[i] == '-' || str[i] == '/' || str[i] == '(' || str[i] == ')')
		{
			flag = flag;
		}
		else {
			flag = flag + 1;
		}
		if (str[i] == '*' || str[i] == '+' || str[i] == '-' || str[i] == '/') {//检测不能两个操作符连在一起
			if (str[i + 1] == '*' || str[i + 1] == '+' || str[i + 1] == '-' || str[i + 1] == '/') {
				flag = flag + 1;
			}
		}
		if (str[i] == '(') {//检测有左括号必须有右括号；
			int p = 0;//标志位检测后面是否有）
			for (i; i < strlen(str); i++) {
				if (str[i] == ')') {
					p = p + 1;
				}
				if (str[i] != ')') {
					p = p;
				}

			}
			if (p == 1) { flag = flag; }
			if (p == 0) { flag = flag + 1; }

		}
	}
	if (flag == 0) {
		cout << "Expression_corrent" << endl;
	}
	if (flag != 0)
	{
		cout << "Expression_error" << endl;
	}
	cout << "flag:" << flag << endl;
	return flag;
}
char output(char s[]){
	float a=0, b=0, c=0, d=0;//用于接收运算式的每一部分的值
	char m=0;//保存运算时的符号 
	int i,j,x,k,y,ok=0,flag;//用于记数,i用于循环记数，
	for (k = 0; k < strlen(s); k++) {
		if (s[k - 1] == ')' && s[k + 1] == '(')//取出中间的运算符
		{
			 m = s[k];
			 ok = k;//ok是表示两个复数中间的那个运算符在数组中第几个位置
		}
	}
	for (i= 0; i < strlen(s); i++){		
		if ((s[i] == '(')&& (i < ok )) {
			flag = 0;
			for (j = 1; ((s[i + j] != '+') && (s[i +j] != '-')); j++) {
				flag = flag + 1;//flag理解为每个数组位数
			}
			for (j = 1; ((s[i + j] != '+') && (s[i +j] != '-')); j++) {
				y = pow(10,flag-j);//次方运算
				x = ((int)s[i + j] - 48) *y;//还原a的每一个部分百位x100，十位x10，个位x1
				a=x+ a;//获取a，累加求出a
			}
		}
		else if (s[i] == '+' && (i < ok)) {//获取b，前面是加号的请况
			flag = 0;
			for (j = 1; ((s[i + j] != ')')); j++) {
				flag = flag + 1;
			}
			for (j = 1; ((s[i + j] != ')') ); j++) {
				y = pow(10, flag - j);
				x = ((int)s[i + j] - 48) * y;
				b = x + b;//获取b
			}
		}
		else if (s[i] == '-' && (i < ok)) {//获取b前面是减号的请况
			flag = 0;
			for (j = 1; ((s[i + j] != ')')); j++) {
				flag = flag + 1;
			}
			for (j = 1; ((s[i + j] != ')')); j++) {
				y = pow(10, flag - j);
				x = ((int)s[i + j] - 48) * y;
				b = x + b;//获取b
			}
			b = -b;
		}
		if ((s[i] == '(') && (i > ok)) {
			flag = 0;
			for (j = 1; ((s[i + j] != '+') && (s[i + j] != '-')); j++) {
				flag = flag + 1;
			}
			for (j = 1; ((s[i + j] != '+') && (s[i + j] != '-')); j++) {
				y = pow(10, flag - j);
				x = ((int)s[i + j] - 48) * y;
				c = x + c;//获取c
			}
		}
		else if ((s[i] == '+') && (i > ok)) {//获取d，前面是加号的请况
			flag = 0;
			for (j =1; ((s[i + j] != ')')); j++) {
				flag = flag + 1;
			}
			for (j = 1; ((s[i + j] != ')')); j++) {
				y = pow(10, flag - j);
				x = ((int)s[i + j] - 48) * y;
				d = x + d;//获取d
			}
		}
		else if (( s[i] == '-') && (i > ok)) {//获取d，前面是减号的请况
			flag = 0;
			for (j = 1; ((s[i + j] != ')')); j++) {
				flag = flag + 1;
			}
			for (j = 1; ((s[i + j] != ')')); j++) {
				y = pow(10, flag - j);
				x = ((int)s[i + j] - 48) * y;
				d = x + d;//获取d
			}
		}
		

	}
	Complex c1(a, b);
	Complex c2(c, d);
	Complex c3;
	if (m == '+')
	{
		c3 = c1 + c2;
		cout << "结果为:";
		c3.display();
	}
	else if (m == '-')
	{
		c3 = c1 - c2;
		cout << "结果为:";
		c3.display();
	}
	else if (m == '*')
	{
		c3 = c1 * c2;
		cout << "结果为:";
		c3.display();
	}
	else if (m == '/')
	{
		c3 = c1 / c2;
		cout << "结果为:";
		c3.display();
	}
	return 0;
}



int main()
{
	int flag = 0;//标志位，判断是否合法
	char str[100];
	cout << "Please_input_your_expression:" << endl;
	cin >> str;
	int p = check(flag, str);
	if (p == 0) {
		output(str);
	}
}


