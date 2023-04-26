#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int a[105],r[105]={0};
bool cmp1(int a,int b)
{
	return a<b;
}

bool cmp2(int a,int b)
{
	return a>b;
}

int main()
{
	int sx=1;
	char c;
	scanf("%c",&c);
	if(c=='D'){sx=-1;}
	int i=0;
	while(~scanf("%d",&a[i]))i++;
	if(sx==1)
	{sort(a,a+i,cmp1);}
	else {sort(a,a+i,cmp2);}
	unique_copy(a,a+i,r);
	int k=0;
	while(r[k]!=0)
	printf("%d ",r[k++]);
	return 0;
}