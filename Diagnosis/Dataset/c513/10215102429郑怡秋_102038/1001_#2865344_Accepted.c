#include <stdio.h>
#include<ctype.h>
#include<string.h>

void itob(int n,char *s,int b)
{
	char *p=s,*st=s;
    const char table[]={"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    int len=0,sign=1;
    if(n<0)
	{
    	sign=-1;n=-n;
	}
	do
	{
		*p++=table[n%b];
		n=n/b;
	}while(n);
	if(sign==-1) *p++='-';
	*p=0;p--;
	int i,j;
	for(i=0,j=strlen(s)-1;i<j;i++,j--)
	{
		int temp=*st;*st=*p;*p=temp;
		st++;
		p--;
	}
}

int main()
{
	int k;
	scanf("%d\n",&k);
    int n,b;
    char s[100];
    for(int i=0;i<k;i++)
    {
    scanf("%d%d",&n,&b);
    itob(n,s,b);
    printf("%s\n",s);
}
    return 0;
}