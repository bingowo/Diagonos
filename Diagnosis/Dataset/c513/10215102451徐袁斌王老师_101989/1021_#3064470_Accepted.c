#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int a[128];
int cmp(const void *b,const void *c)
{
	char *A=(char*)b;
	char *B=(char*)c;
	int i=0;
	while(a[A[i]]==a[B[i]])
	{
		i++;
	}
	return a[A[i]]-a[B[i]];
}
int main()
{
	char ans[100][21],c,b[3000];
	c=getchar();
	while(c!=EOF)
	{
		a[c]=1;a[c-'A'+'a']=1;
		for(int i=2;i<=26;i++)
		{
			scanf("%c",&c);
			a[c]=i;a[c-'A'+'a']=i;
		}
		for(int i=0;i<100;i++)
		{
			for(int j=0;j<20;j++)
			{
				ans[i][j]='\0';
			}
		}
		getchar();
		gets(b);
		int i=0,j=0;
		while(b[i]!='\0')
		{
			if(b[i]==' ') {j++;i++;}
			int k=0;
			while(b[i]!=' '&&b[i]!='\0')
			{
				ans[j][k]=b[i];
				i++;k++;
			}
			ans[j][k]='\0';
		}
		qsort(ans,j+1,sizeof(ans[0]),cmp);
		for(int k=0;k<=j;k++)
		{
			printf("%s ",ans[k]);
		}
		printf("\n");
		c=getchar();
	}
}