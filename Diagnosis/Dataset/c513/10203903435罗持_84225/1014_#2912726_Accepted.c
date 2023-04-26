#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int gcd(int x,int y)
{
	int ret = 1;
	for(int i=2;i*i<x;i++)
		if(x%i==0 && y%i==0) ret = i;
	return ret;
}
int main(void)
{
	int A,B;
	scanf("%d %d",&A,&B);
	int zheng = A/B;
	A %= B;
	int g = gcd(A,B);
	A /= g, B /= g;
	char s1[100] = {0};
	char s2[100] = {0};
	char s[100] = {0};
	int i = 0;
	do{
		s1[i++] = zheng%3;
		zheng /= 3;
	}while(zheng);
	int j=0,q;
	for(i=i-1;i>=0;i--,j++)
		s[j] = s1[i];
	q = j;
	int n = A;
	if(A)
	{
		int p = 0;
		do{
			s2[p++] = A%3;
			A /= 3;
			B /= 3;
		}while(A||(B!=1));
		for(p=p-1;p>=0;p--,q++)
			s[q] = s2[p];
	}
	int l = 0;
	int t = q;
	for(q=q-1;q>=0;q--)
	{
		if(s[q]+1+l>=3){
			s[q] += 1+l-3;
			l = 1;
		}else{
			s[q] += 1+l;
			l = 0;
		}
	}
	for(q=0;q<t;q++)
	{
		s[q] = (s[q]-1==-1?2:s[q]-1);
	}
	for(q=q-1;q>=j;q--)
	{
		if(s[q]==0) t--;
		else break;
	}
	if(l==1)printf("1");
	for(int m=0;m<t;m++)
	{
		printf("%d",s[m]);
		if(n){
			if(m==j-1) putchar('.');
		}
	}
	return 0;
}