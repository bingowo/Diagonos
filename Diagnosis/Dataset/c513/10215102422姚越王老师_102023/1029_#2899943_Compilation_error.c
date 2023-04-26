#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int cmp(const void* a,const void* b)
{
	char *p1=(char*)a,*p2=(char*)b;
	return *p1-*p2;
}
int main()
{
	int n,i,len,j,k=0,q;scanf("%d",&n);
	char a[210],b[210],c=getchar();
	for(i=0;i<n;i++)
	{
		gets(a);
		len=strlen(a);
		int c[len];
		for(j=0;j<len;j++)
		{
			if(a[j]>='A'&&a[j]<='Z')
			{
				c[j]=1;
				b[k++]=a[j];
			}
			else c[j]=-1;
		}
		
		qsort(b,k,sizeof(char),cmp);
		
		k=0;
		printf("case #%d:\n",i);
		for(j=0;j<len;j++)
		{
			if(c[j]==1)printf("%c",b[k++]);
			else {printf("%c",a[j]);}
		}
		printf("\n");
		c=getchar();
	}
	return 0;
}