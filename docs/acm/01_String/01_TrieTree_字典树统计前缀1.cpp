#include<cstdio>
#include<cstring>
using namespace std;

/*
题目描述：给定n个字符串，并给出m个询问，回答含有询问中的字符串个数 
解法：Trie树每个节点存放符合要求的字符串个数 
*/

int ch[410000][30];//存放 Trie 树 
int tot=0;//记录 Trie树的大小 
int s[410000];//记录该结点前缀的字符串个数 
char a[100];

void bt(int root)
{
	int u=root;
	int len=strlen(a+1);
	for(int i=1;i<=len;++i)
	{
		int c=a[i]-'a'+1;//1-a 2-b ... 
		if(!ch[u][c])//如果没有该叶子结点 
			ch[u][c]=++tot;//在当前节点加入子节点的编号 
		u=ch[u][c];//将子节点设为当前节点 
		s[u]++;//子节点的数值加一，用于记录该前缀的字符串个数 
	}
}

int find(int root)
{
	int u=root;
	int len=strlen(a+1);
	for(int i=1;i<=len;++i)
	{
		int c=a[i]-'a'+1;
		if(!ch[u][c])//不存在叶子结点 
			return 0;
		u=ch[u][c];//将叶子结点记为当前结点 
	}
	return s[u];//返回个数 
}

int main()
{
    int n,m;
    scanf("%d",&n);//共n个字符串 
    for(int i=1;i<=n;++i)
	{
        scanf("%s",a+1);//每个字符串从a[1]开始哦 
        bt(0);//存进去 
    }
    scanf("%d",&m);
    for(int i=1;i<=m;++i)
	{
        scanf("%s",a+1);
        printf("%d\n",find(0));
    }
    return 0;
}  
