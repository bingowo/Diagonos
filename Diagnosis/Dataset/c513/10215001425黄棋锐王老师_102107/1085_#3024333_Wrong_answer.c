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
void ctB(char*a,BIG*A)
{
	int i=0,l=strlen(a);
	A->cnt=l;
	for(i=l-1;i>=0;i--)
	 A->v[i]=a[l-1-i]-'0';
}
int MAX(int x,int y)
{
	if(x>y) return x;
	else return y;
}
BIG A_B(BIG A,BIG B)
{   BIG R;
	R.cnt=MAX(A.cnt,B.cnt);
	int carry=0,i=0;
	for(i=0;i<R.cnt;i++)
	{   A.v[i]-=carry;
		if(A.v[i]<B.v[i]) 
		{
		carry=1;
		R.v[i]=A.v[i]+10-B.v[i];
		}
		else {
			carry=0;
			R.v[i]=A.v[i]-B.v[i];
		}
	}
	for(i=R.cnt-1;R.v[i]==0;i--);
	R.cnt=i+1;
	return R;
}
int main() 
{  char a[501]={'\0'};
	char b[501]={'\0'};
	scanf("%s %s",a,b);
	BIG A,B;
	int i;
	for(i=0;i<max;i++) A.v[i]=0,B.v[i]=0;
	ctB(a,&A);
	ctB(b,&B);
	BIG r=A_B(A,B);
	for(i=r.cnt-1;i>=0;i--) printf("%d",r.v[i]);
	return 0;
}