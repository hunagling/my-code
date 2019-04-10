#include<iostream>
#include<string>
#include<fstream>
#include <sstream>
using namespace std;

string readFileIntoString(char* filename)
{
	ifstream ifile(filename);
	//将文件读入到ostringstream对象buf中
	ostringstream buf;
	char ch;
	while (buf && ifile.get(ch))
		buf.put(ch);
	//返回与流对象buf关联的字符串
	return buf.str();
}

int main()
{
	cout << "------位移密码解密-------" << endl;
	//文件名
	char* fn = "a.txt";
	string str,strs;
	str = readFileIntoString(fn);
	strs = str;
	cout << "要解密的文件数据为：";
	cout << str << endl;
	int flag[256];
	int kx=0;//密钥
	int max = 0;
	for (int i = 0; i < (int)str.length(); i++)
	{
		flag[i] = 0;//每一个字符有一个标志位，为它出现的次数。
		for (int j = 0; j <(int)str.length(); j++)
		{
			if(str[i]=str[j])
			{
				flag[i] = flag[i] + 1;
			}
		}

	}
	for (int i = 1; i <(int)str.length(); i++)
	{
		if (flag[i] > flag[max])
			max = i;
	}

	kx = str[max]-'E';

	cout <<"频度分析生成是密钥："<< kx << endl;		
	for (int i = 0; i <(int) strs.length();i++)//解密过程
		{
			if (strs[i] >= 'A' && strs[i] <= 'Z')
			{
				strs[i] = (strs[i] - 'A' - kx) % 26 + 'A'+32;
				if (strs[i] < 97)
					strs[i] = strs[i] + 26;//防止出现其他特殊字符
			}
		}
		cout << "解密结果：";
		cout << strs << endl;
	system("pause");

}