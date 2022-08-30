#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;

//(POJ 3630) http://poj.org/problem?id=3630
/*
题目描述：给定 T 组数据，判断每组数据是否有存在前缀，有-NO，无-YES 
解法：Trie树，参考 "字典树统计前缀1" 
*/

int T,n,tot;
int ch[100005][10];
bool bo[100005];
char s[20];

void clean()
{
	memset(ch,0,sizeof(ch));
	memset(bo,0,sizeof(bo));
	return;
}

bool add(char *s)
{
	int len=strlen(s);
	int u=1;
	bool flag=false;
	for(int i=0;i<len;i++)
	{
		int c=s[i]-'0';
		if(!ch[u][c])
			ch[u][c]=++tot;
		else if(i==len-1)//如果为当前字符串末尾，但该结点还有其他数据 
			flag=true;
		u=ch[u][c];
		if(bo[u])
			flag=true;
	}
	bo[u]=true;
	return flag;
}

int main()
{
	bool ans;
	scanf("%d",&T);
	while(T--)
	{
		ans=false;
		scanf("%d",&n);
		tot=1;
		clean();//初始化 
		for(int i=1;i<=n;i++)
		{
			scanf("%s",s);
			if(add(s))
				ans=true;
		}
		if(ans==true)
			printf("NO\n");
		else
			printf("YES\n");
	}
	
	return 0;
}
