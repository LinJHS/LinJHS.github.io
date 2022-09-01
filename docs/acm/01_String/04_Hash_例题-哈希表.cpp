#include<cstdio>
#include<iostream>
#include<iomanip>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;

/*
����Ŀ������
Ϊ�˰�����Ҫ����Ŀ��˿��ٲ����Ƿ�����������Ҫ���飬������Ҫ���һ��ͼ�����ϵͳ��
���ϵͳ��Ҫ2�ֲ�����
add(s),��ʾ�¼���һ������Ϊs��ͼ�飻
find(s),��ʾ��ѯ�Ƿ����һ������Ϊs��ͼ�顣
�����������ʽ��
�������ʽ��
��һ�а���һ��������n(n<=30000).
����n��,ÿ�и���2 �ֲ����е�ĳһ��ָ��,ָ���ʽΪ:
add s
find s
������s��ָ��(add,find)֮����һ���ո����,���Ǳ�֤���������ĳ��ȶ�������200. ���Լ�����������������.
�������ʽ��
����ÿ��find(s)ָ��,���Ǳ����Ӧ�����һ��yes,no,��ʾ��ǰ����ѯ�����Ƿ������ͼ�����.
ע��:һ��ʼʱͼ�����û�����.����,������ͬ��ĸ��ͬ��Сд������,������Ϊ���ǲ�ͬ��.
������������
4
add Inside C#
find Effective Java
add Effective Java
find Effective Java
�����������
no
yes
*/

const int mod1=1e6+3,mod2=1e6+9,p1=47,p2=79,N=30000;
int tot=0,nxt[N+5],poi[mod1+5],end[N+5];

void insert(int x,int y)						//��Ԫ�ز����ϣ��
{
	nxt[++tot]=poi[x];
	poi[x]=tot;
	end[tot]=y;
}

int query(int x,int y)
{
	for(int i=poi[x];i;i=nxt[i])				//�ҵ����ʾ����
	{
		if(end[i]==y)
		{
			return 1;
		}
	}
	return 0;									//�����ڷ��� 0
}
		
int main()
{
	int n;
	char op[10],s[205];
	scanf("%d",&n);
	while(n--)
	{
		cin>>op;								//���뵽�ո�
		gets(s);								//����ʣ���һ����
		int len=strlen(s),sum1=0,sum2=0;
		for(int i=0;i<len;++i)					//˫��ϣ˼��,�����ؼ��־���һ���ַ���,��С���
		{
			sum1=(sum1*p1+s[i])%mod1;
			sum2=(sum2*p2+s[i])%mod2;
		}
		if(op[0]=='a')
			insert(sum1,sum2);
		else
		{
			if(query(sum1,sum2)) 
				printf("yes\n");
			else
				printf("no\n");
		}
	}
	return 0;
}
