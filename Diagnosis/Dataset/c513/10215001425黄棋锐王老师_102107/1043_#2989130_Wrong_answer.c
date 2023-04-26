#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
void insert(char*s,int j,char c)
{   int i,l=strlen(s);
	s[l+1]='\0';
	for(i=j+1;i<=l;i++) s[i]=s[i-1];
	s[j]=c;
}
int du(char*a)
{	char b[102]={'\0'};
	int i,j=0,flag=0,l=strlen(a);
	if(a[0]!=a[1]) b[j++]=a[0];
	for(i=1;i<l-1;i++)//把消除后的字符放在b中 
	{
		if(a[i]==a[i+1]) continue;
		else {
			if(a[i]==a[i-1]) continue;
			else b[j++]=a[i];
		}
	}
	if(a[l-2]!=a[l-1]) b[j++]=a[l-1];
	for(i=0;i<j-1;i++)
	{
		if(b[i]==b[i+1]) {
			flag=1;
			break;
		}
	}
	if(flag==1) 
	{	
		return du(b);//循环直到没法循环，即无连续字符 
	}
	else {
		int di=l-j;
		return di;
	}
}
int main()
{  int k,T;
	scanf("%d\n",&T);
	for(k=0;k<T;k++)
	{  int t=0,co=0,j,i;
        char a[102]={'\0'};
        char b[102]={'\0'};
        char c[102]={'\0'};
        char d[102]={'\0'};
         gets(a);
         int l=strlen(a);
         for(j=0;j<l;j++)
         {	for(i=0;i<l;i++) b[i]=a[i],c[i]=a[i],d[i]=a[i];
         	insert(b,j,'A');
         	t=du(b);
         	if(t>co) co=t;
         	insert(c,j,'B');
         	t=du(c);
         	if(t>co) co=t;
         	insert(d,j,'C');
         	t=du(d);
         	if(t>co) co=t;
		 }
        	for(i=0;i<l;i++) b[i]=a[i],c[i]=a[i],d[i]=a[i];
        	b[l]='A';c[l]='B';d[l]='C';
       		t=du(b);
         	if(t>co) co=t;
         	t=du(c);
         	if(t>co) co=t;
         	t=du(d);
         	if(t>co) co=t;
	 		printf("case #%d:\n",k);
	 		printf("%d\n",co);
	}
	return 0;
}