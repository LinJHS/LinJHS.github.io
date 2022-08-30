#include<cstdio>
#include<cstring>
using namespace std;

/*
题目描述：给定n个字符串，并给出m个询问，回答含有询问中的字符串个数 
解法：Trie树每个节点存放符合要求的字符串个数 
（和 1 的很像） 
*/

struct node{
	int s,v[27];//s存放当前节点前缀的符合要求的字符串个数，v存放叶子结点位置 
	node()//无参构造函数，用于进行初始化 
	{
		s=0;
		memset(v,-1,sizeof(v));
	}
}t[410000];//定义叶子结点 

int tot=0;
char a[100];

void bt(int root)
{
	int x=root;
	int len=strlen(a+1);
	for(int i=1;i<=len;++i)
	{
		int y=a[i]-'a'+1;
		if(t[x].v[y]==-1)
			t[x].v[y]=++tot;
		x=t[x].v[y];
		t[x].s++;
	}
}

int find(int root)
{
	int x=root;
	int len=strlen(a+1);
	for(int i=1;i<=len;++i)
	{
		int y=a[i]-'a'+1;
		if(t[x].v[y]==-1)
			return  0;
		x=t[x].v[y]; 
	}
	return t[x].s;
}

int main()
{
	int n,m;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%s",a+1);
		bt(0);
	}
	scanf("%d",&m);
	for(int i=1;i<=m;++i)
	{
		scanf("%s",a+1);
		printf("%d\n",find(0));
	}
	return 0;
} 
