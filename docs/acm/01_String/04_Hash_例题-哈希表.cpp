#include<cstdio>
#include<iostream>
#include<iomanip>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;

/*
【题目描述】
为了帮助想要借书的客人快速查找是否有他们所需要的书，我们需要设计一个图书查找系统。
这个系统需要2种操作：
add(s),表示新加入一本书名为s的图书；
find(s),表示查询是否存在一本书名为s的图书。
【输入输出格式】
【输入格式】
第一行包括一个正整数n(n<=30000).
以下n行,每行给出2 种操作中的某一种指令,指令格式为:
add s
find s
在书名s与指令(add,find)之间有一个空格隔开,我们保证所有书名的长度都不超过200. 可以假设读入数据是无误的.
【输出格式】
对于每条find(s)指令,我们必须对应的输出一行yes,no,表示当前所查询的数是否存在于图书馆内.
注意:一开始时图书馆是没有书的.并且,对于相同字母不同大小写的书名,我们认为它是不同的.
【输入样例】
4
add Inside C#
find Effective Java
add Effective Java
find Effective Java
【输出样例】
no
yes
*/

const int mod1=1e6+3,mod2=1e6+9,p1=47,p2=79,N=30000;
int tot=0,nxt[N+5],poi[mod1+5],end[N+5];

void insert(int x,int y)						//将元素插入哈希表
{
	nxt[++tot]=poi[x];
	poi[x]=tot;
	end[tot]=y;
}

int query(int x,int y)
{
	for(int i=poi[x];i;i=nxt[i])				//找到则表示存在
	{
		if(end[i]==y)
		{
			return 1;
		}
	}
	return 0;									//不存在返回 0
}
		
int main()
{
	int n;
	char op[10],s[205];
	scanf("%d",&n);
	while(n--)
	{
		cin>>op;								//读入到空格
		gets(s);								//读入剩余的一整行
		int len=strlen(s),sum1=0,sum2=0;
		for(int i=0;i<len;++i)					//双哈希思想,两个关键字决定一个字符串,减小误差
		{
			sum1=(sum1*p1+s[i])%mod1;
			sum2=(sum2*p2+s[i])%mod2;
		}
		if(op[0]=='a')
			insert(sum1,sum2);
		else
		{
			if(query(sum1,sum2)) 
				printf("yes\n");
			else
				printf("no\n");
		}
	}
	return 0;
}
