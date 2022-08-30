#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;

//(POJ 3630) http://poj.org/problem?id=3630
/*
��Ŀ���������� T �����ݣ��ж�ÿ�������Ƿ��д���ǰ׺����-NO����-YES 
�ⷨ��Trie�����ο� "�ֵ���ͳ��ǰ׺1" 
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
		else if(i==len-1)//���Ϊ��ǰ�ַ���ĩβ�����ý�㻹���������� 
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
		clean();//��ʼ�� 
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
