#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int prime[26]={97,91,89,83,79,73,71,67,61,59,53,47,43,41,37,31,29,23,19,17,13,11,7,5,3,2};
void Readnumber(char *s,int *a)
{
	int n=strlen(s)-1,cnt=0;
	for(n;n>=0;n--)
	{
		if(s[n]==',')
		{
			char* p=s+n+1;
			char num[1005];
			strcpy(num,p);
			a[25-cnt]=atoi(num);
			cnt++;
			s[n]=0;
		}
	}
	a[25-cnt]=atoi(s);
}
void add(int* a,int* b)//把b加到a上； 
{
	int i,j,k;
	for(i=0;i<100;i++)if(a[i])break;
	for(j=0;j<100;j++)if(b[j])break;
	int carry=0;
	for(k=99;k>=(i>j?j:i);k--)
	{
		a[k]+=b[k];
		a[k]+=carry;
		if(a[k]>=10){a[k]%=10;carry=1;}
		else carry=0;
	}
	a[k]=carry;
}
void mul(int A,int* a)//a乘以A，A最多为两位数 
{
	int tmp=A;
	if(A>=10)A%=10;
	int b[100]={0},c[100]={0};
	memcpy(b,a,100*sizeof(int));
	memcpy(c,a,100*sizeof(int));
	int i,j,k;
	for(i=0;i<100;i++)if(a[i])break;
	int carry=0;
	for(j=99;j>=i;j--)
	{
		int temp=b[j]*A+carry;
		b[j]=temp%10;
		carry=temp/10;
	}
	b[j]=carry;
	if(tmp/10==0)
	{
		memcpy(a,b,100*sizeof(int));
		return;
	}
	else for(k=i-1;k<99;k++)c[k]=c[k+1];
	c[99]=0;
	carry=0;
	A=tmp/10;
	for(k=99;k>=i-1;k--)
	{
		int temp=c[k]*A+carry;
		c[k]=temp%10;
		carry=temp/10;
	}
	c[k]=carry;
	add(c,b);
	memcpy(a,c,100*sizeof(int));
}
int main()
{
	char s[1005];scanf("%s",s);
	int data[26]={0};
	Readnumber(s,data);
	int a[100]={0},b[100]={0},weight[100]={0};
	weight[99]=1;b[99]=1;
	for(int i=25;i>=0;i--)
	{
		mul(data[i],b);
		add(a,b);
		mul(prime[i],weight);
		memcpy(b,weight,100*sizeof(int));
	}
	int i;
	for(i=0;i<100;i++)if(a[i])break;
	for(i;i<100;i++)printf("%d",a[i]);
	return 0;
}