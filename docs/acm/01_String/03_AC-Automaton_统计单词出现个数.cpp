#include<cstdio>
#include<cstring>
using namespace std;

/*
题目描述：给定 n 个单词，求这 n 个单词出现在文章 S 中的个数（不重复计算）。 
解法：AC自动机（Trie树上的KMP） 
*/

int ans,cnt;
int ch[500005][30],bo[500005];//ch 存放 Trie 树，bo 存放单词末尾标记 
int nxt[500005];//失配指针，有时也写作 fail[] 
int que[500005];//也就是 BFS 的 h 数组 

void make(char *s)//将字符串 s 存入 Trie 树中。 
{
	int u=1,len=strlen(s);
	for(int i=0;i<len;++i)
	{
		int c=s[i]-'a';
		if(!ch[u][c])
		{
			ch[u][c]=++cnt;
			memset(ch[cnt],0,sizeof(ch[cnt]));
		}
		u=ch[u][c];
	}
	bo[u]++;
	return;
}

void bfs()
{
	for(int i=0;i<=25;++i)
		ch[0][i]=1;//0 结点的每一个字符都指向 root 结点（初始化） 
	que[1]=1;
	nxt[1]=0;//构建 nxt 数组，root 默认指向 0 结点 
	for(int q1=1,q2=1;q1<=q2;++q1)//BFS 
	{
		int u=que[q1];
		for(int i=0;i<=25;++i)
		{
			if(!ch[u][i])//如果到叶子结点的话则通过 nxt 往回跳 
				ch[u][i]=ch[nxt[u]][i];
			else
			{
				que[++q2]=ch[u][i];
				int v=nxt[u];
				//符合条件的 v ：查找父亲的前缀指针(nxt)指向的节点，通过 nxt 一直跳， 
				//直到找到该结点的有通过 i 连接的儿子 
				while(v>0 && !ch[v][i])//通过 nxt 一直跳直到找到符合的 
					v=nxt[v];
				nxt[ch[u][i]]=ch[v][i];//nxt 的跳转 
			}
		}
	}
}

void find(char *s)
{
	int u=1,len=strlen(s),c,k;
	for(int i=0;i<=len;++i)
	{
		c=s[i]-'a';
		k=ch[u][c];
		while(k>1)//跳到 0 结点自动退出循环 
		{
			ans+=bo[k];//单词末尾-1 非单词末尾-0 
			bo[k]=0;//防止重复计算 
			k=nxt[k];//通过 nxt 往回跳 
		}
		u=ch[u][c];
	}
	return;
}

int main()
{
	int t,n;
	char s[1000010];
	scanf("%d",&t);
	while(t--)
	{
		ans=0;
		cnt=1;
		memset(bo,0,sizeof(bo));
		for(int i=0;i<26;++i)
			ch[0][i]=1,ch[1][i]=0;
		scanf("%d",&n);
		for(int i=1;i<=n;++i)
		{
			scanf("%s",s);
			make(s);
		}
		bfs();
		scanf("%s",s);
		find(s);
		printf("%d\n",ans);
	}
	return 0;
}
