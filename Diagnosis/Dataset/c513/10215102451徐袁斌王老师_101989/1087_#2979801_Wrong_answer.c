#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int k=0;
void add(int a[],int b[])
{   int i;
    for(i=101;i>0;i--)
    {
        a[i] += b[i];
        a[i-1] += a[i]/10;
        a[i] %= 10;
    }
}
void f(int a[])
{
	int i=0;
	int b[110]={0};
	for(int j=0;j<110;j++) b[j]=0; 
	while(i<k)
	{
		if(a[i]==a[i+1])
		{
			for(int j=0;j<110;j++) b[j]=0; 
			b[i+1]=1;
			add(a,b);
			f(a);
			i++;
		}
		else
		{
			i++;
		}
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		int a[110]={0},b[110]={0};
		for(int j=0;j<110;j++) b[j]=0; 
	    char s[101];
	    scanf("%s",s);    
	    int j=0;
	    while(s[j]!='\0')
	    {
			a[j+1]=s[j]-'0';
			j++;k++;
		}
		b[k]=1;
		add(a,b);
		f(a);
		printf("case #%d:\n",i);
		j=0;while(a[j]==0) j++;
		for(;j<k+1;j++)
		{
			printf("%d",a[j]);
		}
		printf("\n");
		k=0;
	}
}