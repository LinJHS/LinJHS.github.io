#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

//Âå¹È P2860 [USACO06JAN]ÈßÓàÂ·¾¶Redundant Paths 

int read()
{
	int x=0;
	bool f=false;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')
			f=true;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return f?-x:x;
}

struct edge{
	int to,next,op;
}a[20010];

int dfn[5005],low[10010];
int stack[5005],con[5005];
int belong[5005],first[5005];
int vis[20010];
int n,m,tot,top,bcc,ans,cnt;

void add(int x,int y)
{
	tot++;
	a[tot].to=y;
	a[tot].next=first[x];
	first[x]=tot;
	a[tot].op=tot+1;
	
	tot++;
	a[tot].to=x;
	a[tot].next=first[y];
	first[y]=tot;
	a[tot].op=tot-1;
}

void dfs(int x)
{
	int y;
	low[x]=dfn[x]=++cnt;
	stack[++top]=x;
	for(int i=first[x];i;i=a[i].next)
		if(!vis[a[i].op])
		{
			vis[i]=1;
			y=a[i].to;
			if(!dfn[y])
			{
				dfs(y);
				low[x]=min(low[x],low[y]);
			}
			else
				low[x]=min(low[x],dfn[y]);
		}
		else
			vis[i]=1;
	int i;
	if(low[x]==dfn[x])
	{
		bcc++;
		do
		{
			i=stack[top--];
			belong[i]=bcc;
		}while(i!=x);
	}
}

int main()
{
	n=read();
	m=read();
	for(int i=1;i<=m;i++)
		add(read(),read());
	dfs(1);
	int j;
	for(int i=1;i<=n;i++)
		for(int k=first[i];k;k=a[k].next)
			if(vis[a[k].op])
			{
				vis[k]=0;
				j=a[k].to;
				if(belong[i]!=belong[j])
				{
					con[belong[i]]++;
					con[belong[j]]++;
				}
			}
			else
				vis[k]=0;
	for(int i=1;i<=bcc;i++)
		if(con[i]==1)
			ans++;
	printf("%d\n",(ans+1)/2);
	return 0;
}

