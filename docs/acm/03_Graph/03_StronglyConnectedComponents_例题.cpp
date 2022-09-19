#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

//Âå¹È P2341 [HAOI2006]ÊÜ»¶Ó­µÄÅ£

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

int n,m;
int to[50005],nxt[50005],first[10005];
int col,num;
int dfn[10005],low[10005],de[10005],si[10005];
int tot;
int co[10005];
int top;
int st[10005];
int ans;

void add(int x,int y)
{
	to[++tot]=y;
	nxt[tot]=first[x];
	first[x]=tot;
}

void Tarjan(int u)
{
	dfn[u]=low[u]=++num;
	st[++top]=u;
	for(int i=first[u];i;i=nxt[i])
	{
		int v=to[i];
		if(!dfn[v])
		{
			Tarjan(v);
			low[u]=min(low[u],low[v]);
		}
		else if(!co[v])
				low[u]=min(low[u],dfn[v]);
	}
	if(low[u]==dfn[u])
	{
		co[u]=++col;
		++si[col];
		while(st[top]!=u)
		{
			++si[col];
			co[st[top]]=col;
			--top;
		}
		--top;
	}
}

int main()
{
	n=read();
	m=read();
	for(int i=1;i<=m;i++)
		add(read(),read());
	for(int i=1;i<=n;i++)
		if(!dfn[i])
			Tarjan(i);
	for(int i=1;i<=n;i++)
		for(int j=first[i];j;j=nxt[j])
			if(co[i]!=co[to[j]])
				de[co[to[j]]]++;
	int u=0;
	for(int i=1;i<=col;i++)
		if(!de[i])
		{
			ans=si[i];
			u++;
		}
	if(u==1)
		printf("%d",ans);
	else
		printf("0");
	return 0;
}

