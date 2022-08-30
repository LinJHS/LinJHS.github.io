#include<cstdio>
#include<cstring>
using namespace std;

/*
��Ŀ���������� n �����ʣ����� n �����ʳ��������� S �еĸ��������ظ����㣩�� 
�ⷨ��AC�Զ�����Trie���ϵ�KMP�� 
*/

int ans,cnt;
int ch[500005][30],bo[500005];//ch ��� Trie ����bo ��ŵ���ĩβ��� 
int nxt[500005];//ʧ��ָ�룬��ʱҲд�� fail[] 
int que[500005];//Ҳ���� BFS �� h ���� 

void make(char *s)//���ַ��� s ���� Trie ���С� 
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
		ch[0][i]=1;//0 ����ÿһ���ַ���ָ�� root ��㣨��ʼ���� 
	que[1]=1;
	nxt[1]=0;//���� nxt ���飬root Ĭ��ָ�� 0 ��� 
	for(int q1=1,q2=1;q1<=q2;++q1)//BFS 
	{
		int u=que[q1];
		for(int i=0;i<=25;++i)
		{
			if(!ch[u][i])//�����Ҷ�ӽ��Ļ���ͨ�� nxt ������ 
				ch[u][i]=ch[nxt[u]][i];
			else
			{
				que[++q2]=ch[u][i];
				int v=nxt[u];
				//���������� v �����Ҹ��׵�ǰ׺ָ��(nxt)ָ��Ľڵ㣬ͨ�� nxt һֱ���� 
				//ֱ���ҵ��ý�����ͨ�� i ���ӵĶ��� 
				while(v>0 && !ch[v][i])//ͨ�� nxt һֱ��ֱ���ҵ����ϵ� 
					v=nxt[v];
				nxt[ch[u][i]]=ch[v][i];//nxt ����ת 
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
		while(k>1)//���� 0 ����Զ��˳�ѭ�� 
		{
			ans+=bo[k];//����ĩβ-1 �ǵ���ĩβ-0 
			bo[k]=0;//��ֹ�ظ����� 
			k=nxt[k];//ͨ�� nxt ������ 
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
