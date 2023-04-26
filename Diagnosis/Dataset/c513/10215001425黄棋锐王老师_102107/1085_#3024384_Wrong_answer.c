#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define max 500
typedef struct
{
	int cnt;
	int v[max];
}BIG;
void ctB(char*A,BIG*a)//转换 
{
	int l=strlen(A),i=0;
	for(i=l-1;i>=0;i--)
	{  
		a->v[a->cnt++]=A[i]-'0';	
	}
}
int MAX(int x,int y)
{
	if(x>y) return x;
	else return y;
}
void A_B(BIG*A,BIG*B)
{   int carry=0,i=0;
	for(i=0;i<A->cnt;i++)
	{   A->v[i]-=carry;
		if(A->v[i]<B->v[i]) 
		{
		carry=1;
		A->v[i]=A->v[i]+10-B->v[i];
		}
		else {
			carry=0;
			A->v[i]=A->v[i]-B->v[i];
		}
	}
	for(i=A->cnt-1;A->v[i]==0;i--);
	A->cnt=i+1;
}
int main() 
{  
	char a[501]={'\0'};
	char b[501]={'\0'};
	while(scanf("%s %s",a,b)!=EOF)
{
	BIG A,B;
	A.cnt=0;
	B.cnt=0;
	int i;
	for(i=0;i<max;i++) A.v[i]=0,B.v[i]=0;
	ctB(a,&A);
	ctB(b,&B);
	if(strcmp(a,b)>0) 
	{
	A_B(&A,&B);
	for(i=A.cnt-1;i>=0;i--) printf("%d",A.v[i]);
	}
	else
	{
	A_B(&B,&A);
	printf("-");
	for(i=B.cnt-1;i>=0;i--) printf("%d",B.v[i]);
	}
	putchar('\n');
	for(i=0;i<502;i++) a[i]='\0',b[i]='\0';
}
	return 0;
}