#include <bits/stdc++.h>
using namespace std;

/*
题目描述：给定若干个点，求凸包的周长 
解法：从左下角开始逆时针找到所有的点 
*/ 
const int N=1050;//点数 

struct Point{
    int x,y;
}p[N],s[N];//p存放输入的点，s存放凸包的点（从0开始存哦） 

int n;//总点数 
int top;//凸包的点数-1，也就是最后一个点的位置 

int cross(Point a,Point b,Point c)//向量叉乘，绝对值大小为构成的平行四边形面积 
{
	return (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);
}

double dis(Point a,Point b)//两点间距离 
{
	return sqrt((double)(a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

bool cmp(Point a,Point b)//使所有点按对于p0逆时针排列，如果共线的话距离近的排在前面 
{
	int t=cross(p[0],a,b);//共线-0，对于p0来说，a在b顺指针方向-正，a在b逆时针方向-负 
	if(t>0 || t==0 && dis(p[0],a)<dis(p[0],b))
		return true;
	else
		return false;
}

void init(int n)
{
	scanf("%d%d",&p[0].x,&p[0].y);
	Point p0={p[0].x,p[0].y};//p0用于存放左下角的点 
	int k=0;
	for(int i=1;i<n;i++)
	{
		scanf("%d%d",&p[i].x,&p[i].y);
		if(p[i].y<p0.y || p[i].y==p0.y && p[i].x<p0.x)//找到左下角的点 
		{
			p0=p[i];
			k=i;
		}
	}
	p[k]=p[0];
	p[0]=p0;//把左下角的点移到最前面 
	sort(p+1,p+n,cmp);//剩下的点排序 
}

void graham(int n)
{
	if(n==1)//如果只有一个点，那就是一个点 
	{
		top=0;
		s[0]=p[0];
	}
	else if(n==2)//同理，两个点 
	{
		top=1;
		s[0]=p[0];
		s[1]=p[1];
	}
	else//不止两个点 
	{
		top=1;
		s[0]=p[0];
		s[1]=p[1];
		for(int i=2;i<n;i++)
		{
			while(top>0 && cross(s[top-1],s[top],p[i])<=0)//与新点不构成逆时针也就是凸包的话 
				top--;//删掉最后一个点 
			s[++top]=p[i];//加入新的点 
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

