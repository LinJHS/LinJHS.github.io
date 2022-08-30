#include<cstdio>
#include<iostream>
#include<iomanip>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;

//(Hdu 2087) http://acm.hdu.edu.cn/showproblem.php?pid=2087
/*
题目描述：给定两个字符串 A、B ，求 A 中有多少个 B 的子串（不可重叠） 
解法：KMP（详见txt文档） 
*/ 

char A[1007],B[1007];
int P[1007];//P 数组就是 next 数组。 
int n,m;

void pre()//求 P 数组（即 next 数组） 
{
	P[1]=0;//记得本题中字符串从 1 开始 
	int j=0;
	for(int i=1;i<m;i++)
	{
		while(j>0 && B[j+1]!=B[i+1])
			j=P[j];
		if(B[j+1]==B[i+1])
			j++;
		P[i+1]=j;
	}
}

int kmp()
{
	int ans=0,j=0;
	for(int i=0;i<n;i++)
	{
		while(j>0 && B[j+1]!=A[i+1])
			j=P[j];
		if(B[j+1]==A[i+1])
			j++;
		if(j==m)
		{
			ans++;
			j=0;
		}
	}
	return ans;
}

int main()
{
	while(cin>>A+1)
	{
		if(A[1]=='#')
			break;
		scanf("%s",B+1);
		m=strlen(B+1);
		n=strlen(A+1);
		pre();
		printf("%d\n",kmp());
	}
	return 0;
}
