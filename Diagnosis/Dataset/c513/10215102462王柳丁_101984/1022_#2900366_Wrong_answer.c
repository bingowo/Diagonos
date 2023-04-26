#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int n;

int cmp(const void *a,const void *b)
{
	char a1[2000000/n];
	char b1[2000000/n];
	strcpy(a1,(char*)a);
    strcpy(b1,(char*)b);
    int j;
    int com1,com2;
    for(j=0;j<strlen(a1)&&j<strlen(b1);j++)
    {
    	if(a1[j]=='@')com1=a1[j+1];
    	if(b1[j]=='@')com2=b1[j+1];
	}
	if(com1!=com2)return (com1>com2)?1:-1;
	else{
		for(j=0;a1[j]!='@'&&b1[j]!='@';j++)
		{
			if(a1[j]!=b1[j])return (a1[j]<b1[j])?1:-1;
		}
	}
}

int main ()
{
	int i;
	scanf("%d",&n);
	char a[n][2000000/n];
	for(i=0;i<n;i++)
	{
		scanf("%s",a[i]);
	}
	qsort(a,n,sizeof(a[0]),cmp);
	for(i=0;i<n;i++)
	{
		printf("%s\n",a[i]);
	}
	return 0;
}