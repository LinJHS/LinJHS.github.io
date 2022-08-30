#include <bits/stdc++.h>
using namespace std;

/*
��Ŀ�������������ɸ��㣬��͹�����ܳ� 
�ⷨ�������½ǿ�ʼ��ʱ���ҵ����еĵ� 
*/ 
const int N=1050;//���� 

struct Point{
    int x,y;
}p[N],s[N];//p�������ĵ㣬s���͹���ĵ㣨��0��ʼ��Ŷ�� 

int n;//�ܵ��� 
int top;//͹���ĵ���-1��Ҳ�������һ�����λ�� 

int cross(Point a,Point b,Point c)//������ˣ�����ֵ��СΪ���ɵ�ƽ���ı������ 
{
	return (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);
}

double dis(Point a,Point b)//�������� 
{
	return sqrt((double)(a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

bool cmp(Point a,Point b)//ʹ���е㰴����p0��ʱ�����У�������ߵĻ������������ǰ�� 
{
	int t=cross(p[0],a,b);//����-0������p0��˵��a��b˳ָ�뷽��-����a��b��ʱ�뷽��-�� 
	if(t>0 || t==0 && dis(p[0],a)<dis(p[0],b))
		return true;
	else
		return false;
}

void init(int n)
{
	scanf("%d%d",&p[0].x,&p[0].y);
	Point p0={p[0].x,p[0].y};//p0���ڴ�����½ǵĵ� 
	int k=0;
	for(int i=1;i<n;i++)
	{
		scanf("%d%d",&p[i].x,&p[i].y);
		if(p[i].y<p0.y || p[i].y==p0.y && p[i].x<p0.x)//�ҵ����½ǵĵ� 
		{
			p0=p[i];
			k=i;
		}
	}
	p[k]=p[0];
	p[0]=p0;//�����½ǵĵ��Ƶ���ǰ�� 
	sort(p+1,p+n,cmp);//ʣ�µĵ����� 
}

void graham(int n)
{
	if(n==1)//���ֻ��һ���㣬�Ǿ���һ���� 
	{
		top=0;
		s[0]=p[0];
	}
	else if(n==2)//ͬ�������� 
	{
		top=1;
		s[0]=p[0];
		s[1]=p[1];
	}
	else//��ֹ������ 
	{
		top=1;
		s[0]=p[0];
		s[1]=p[1];
		for(int i=2;i<n;i++)
		{
			while(top>0 && cross(s[top-1],s[top],p[i])<=0)//���µ㲻������ʱ��Ҳ����͹���Ļ� 
				top--;//ɾ�����һ���� 
			s[++top]=p[i];//�����µĵ� 
		}
	}
}

int main()
{
	while(scanf("%d",&n)>0 && n)
	{
		init(n);
		graham(n);
		double ans=0;
		for(int i=1;i<=top;i++)
		{
			ans+=dis(s[i],s[i-1]);
		}
		ans+=dis(s[0],s[top]);
		if(n==2)
		{
			ans/=2;
		}
		printf("%.2lf\n",ans);
	}
	return 0;
}

