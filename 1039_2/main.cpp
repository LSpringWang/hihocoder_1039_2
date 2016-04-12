/*
题目来源：hihocoder 题库 1039题
完成人： LeoSpring

功能：给定一个包含只包含A、B、C三种字符的字符串，
我们可以在任意位置添加一个字符（A、B、C），统计可以连连看消除的最大字符数，相同即可消除

例子：
 给定"ABCBCCCAA"，我们可以在第二个位置后面插入'C',得到“ABCCBCCCAA”,消除后只有A,可以消除9个字符。

输入： 第一行输入：测试的数据个数。
       第2-n行，输入字符串
输出：每个字符串的最大消除个数。
*/

#include <iostream>
#include<string>
using namespace std;
int delSameString(string str);
int main()
{
	string str;
	int t = 0;
	int num = 0;
	int maxnum = 0;
	cin>>t;
	while (t>0)
	{
		cin>>str;
		string str2 = str;
		int strlen = str.length();
		int i = 0;
		for (i=0;i<strlen;i++)
		{
			str2.insert(i,"A");
			num = delSameString(str2);
			if(num>maxnum)
				maxnum = num;
			str2 = str;
	
			str2 = str2.insert(i,"B");
			num = delSameString(str2);
			if(num>maxnum)
				maxnum = num;
			str2 = str;

			str2 = str2.insert(i,"C");
			num = delSameString(str2);
			if(num>maxnum)
				maxnum = num;
			str2 = str;
		}
		cout<<maxnum<<endl;
		maxnum = 0;
		t--;
	}

		system("pause");
	return 0;
}
int delSameString(string str)
{
	int len = str.length();
	if(len<=1)
		return 0;

	int i = 0;
	int delNum = 0;
	string str2 = "";

		if(str[0]!= str[1])
		{
			str2 += str[0];
		}

		for(i=1;i<len-1;i++)
		{

		   if (str[i]!=str[i-1] && str[i]!=str[i+1])
		   {
			   str2 += str[i];
		   }
		}
		if(str[i] != str[i-1])
		{
			str2+= str[i];
		}
	    delNum = str.length() - str2.length();
		if(delNum == 0)
			return 0;
	return delNum + delSameString(str2);
}