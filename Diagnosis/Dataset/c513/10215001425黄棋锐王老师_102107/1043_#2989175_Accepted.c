#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
void insert(char*s,int j,char c)
{   int i,l=strlen(s);
	for(i=l;i>=j+1;i--) s[i]=s[i-1];
	s[j]=c;
}
int du(char*a)
{	char b[200]={'\0'};
	int i,j=0,flag=0,l=strlen(a);
	if(a[0]!=a[1]) b[j++]=a[0];
	for(i=1;i<l-1;i++)//把消除后的字符放在b中 
	{
		if(a[i]==a[i+1]) continue;//用到i+1，终点len-1
		else {
			if(a[i]==a[i-1]) continue;//用到i-1，起点1
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
		return du(b);//循环直到没法循环，即无连续字符 
	
	else return j;

}
int main()
{  int k,T;
	scanf("%d\n",&T);
	for(k=0;k<T;k++)
	{  int t=0,co=0,j,i;
        char a[200]={'\0'};
         gets(a);
         int l=strlen(a);
         for(j=0;j<l;j++)
         {	char b[200]={'\0'};
        	char c[200]={'\0'};
        	char d[200]={'\0'};
		 for(i=0;i<l;i++) b[i]=a[i],c[i]=a[i],d[i]=a[i];
         	insert(b,j,'A');
         	t=l+1-du(b);//l+1,插入的字符也算 
         	if(t>co) co=t;
         	insert(c,j,'C');
         	t=l+1-du(c);
         	if(t>co) co=t;
         	insert(d,j,'B');
         	t=l+1-du(d);
         	if(t>co) co=t;
		 }
		 char e[200]={'\0'};char f[200]={'\0'};char g[200]={'\0'};
		 for(i=0;i<l;i++) e[i]=a[i],f[i]=a[i],g[i]=a[i];
        	e[l]='A';f[l]='B';g[l]='C';
       		t=l+1-du(e);
         	if(t>co) co=t;
         	t=l+1-du(f);
         	if(t>co) co=t;
         	t=l+1-du(g);
         	if(t>co) co=t;
	 		printf("case #%d:\n",k);
	 		printf("%d\n",co);
	}
	return 0;
}