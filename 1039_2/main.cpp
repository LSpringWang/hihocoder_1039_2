/*
��Ŀ��Դ��hihocoder ��� 1039��
����ˣ� LeoSpring

���ܣ�����һ������ֻ����A��B��C�����ַ����ַ�����
���ǿ���������λ�����һ���ַ���A��B��C����ͳ�ƿ�������������������ַ�������ͬ��������

���ӣ�
 ����"ABCBCCCAA"�����ǿ����ڵڶ���λ�ú������'C',�õ���ABCCBCCCAA��,������ֻ��A,��������9���ַ���

���룺 ��һ�����룺���Ե����ݸ�����
       ��2-n�У������ַ���
�����ÿ���ַ������������������
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