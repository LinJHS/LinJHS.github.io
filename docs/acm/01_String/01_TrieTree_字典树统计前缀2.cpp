#include<cstdio>
#include<cstring>
using namespace std;

/*
��Ŀ����������n���ַ�����������m��ѯ�ʣ��ش���ѯ���е��ַ������� 
�ⷨ��Trie��ÿ���ڵ��ŷ���Ҫ����ַ������� 
���� 1 �ĺ��� 
*/

struct node{
	int s,v[27];//s��ŵ�ǰ�ڵ�ǰ׺�ķ���Ҫ����ַ���������v���Ҷ�ӽ��λ�� 
	node()//�޲ι��캯�������ڽ��г�ʼ�� 
	{
		s=0;
		memset(v,-1,sizeof(v));
	}
}t[410000];//����Ҷ�ӽ�� 

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
