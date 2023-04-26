#include <stdio.h>
#include <stdlib.h>
void f(int a[],int b[],int tump,int i,int j)
{
	int res=0;
	int carry=0;
	for(int k=1;k<=i;k++)
	{	
		int l=b[j-k];
		if(j-k<0) l=0;
		int n=a[i-k]-l+carry;
		if(n<0)
		{
			n+=10;
			a[i-k]=n;
			carry=-1;
		}
		else
		{
			a[i-k]=n;
			carry=0;
		}
	}
	int s=0;
	while(s<i&&a[s]==0) s++;
	if(s!=i&&tump==1) printf("-");
	if(s==i) printf("0\n");
	else 
	{
	for(int k=s;k<i;k++) printf("%d",a[k]);
	printf("\n");
	}
}
int main()
{
	
	int a[501],b[501];
	char c;
	int i=0,j=0;
	while((c=getchar())!=' ') a[i++]=c-'0';
	while((c=getchar())!='\n') b[j++]=c-'0';
	while(c!=EOF)
	{
	if(i<j) f(b,a,1,j,i);
	else if(i>j) f(a,b,0,i,j);
	else 
	{	int l=0;
		while(a[l]==b[l]) l++;
		if(a[l]>b[l]) f(a,b,0,i,j);
		else f(b,a,1,j,i);
	}
	while(i) a[i--]=0;
	while(j) b[j--]=0;
	while((c=getchar())!=' ') a[i++]=c-'0';
	while((c=getchar())!='\n') b[j++]=c-'0';
	}
	return 0;
}