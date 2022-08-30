#include<cstdio>
#include<cstring>
using namespace std;

/*
��Ŀ����������n���ַ�����������m��ѯ�ʣ��ش���ѯ���е��ַ������� 
�ⷨ��Trie��ÿ���ڵ��ŷ���Ҫ����ַ������� 
*/

int ch[410000][30];//��� Trie �� 
int tot=0;//��¼ Trie���Ĵ�С 
int s[410000];//��¼�ý��ǰ׺���ַ������� 
char a[100];

void bt(int root)
{
	int u=root;
	int len=strlen(a+1);
	for(int i=1;i<=len;++i)
	{
		int c=a[i]-'a'+1;//1-a 2-b ... 
		if(!ch[u][c])//���û�и�Ҷ�ӽ�� 
			ch[u][c]=++tot;//�ڵ�ǰ�ڵ�����ӽڵ�ı�� 
		u=ch[u][c];//���ӽڵ���Ϊ��ǰ�ڵ� 
		s[u]++;//�ӽڵ����ֵ��һ�����ڼ�¼��ǰ׺���ַ������� 
	}
}

int find(int root)
{
	int u=root;
	int len=strlen(a+1);
	for(int i=1;i<=len;++i)
	{
		int c=a[i]-'a'+1;
		if(!ch[u][c])//������Ҷ�ӽ�� 
			return 0;
		u=ch[u][c];//��Ҷ�ӽ���Ϊ��ǰ��� 
	}
	return s[u];//���ظ��� 
}

int main()
{
    int n,m;
    scanf("%d",&n);//��n���ַ��� 
    for(int i=1;i<=n;++i)
	{
        scanf("%s",a+1);//ÿ���ַ�����a[1]��ʼŶ 
        bt(0);//���ȥ 
    }
    scanf("%d",&m);
    for(int i=1;i<=m;++i)
	{
        scanf("%s",a+1);
        printf("%d\n",find(0));
    }
    return 0;
}  
