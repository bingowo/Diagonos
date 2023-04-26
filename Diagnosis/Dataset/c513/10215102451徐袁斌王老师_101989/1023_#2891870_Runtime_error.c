#include<stdio.h>
#include<math.h>
#include<string.h>
int cmp(const void *a,const void *b)
{
	char *p1,*p2;
	p1=*((char**)a);
	p2=*((char**)b);
	return strcmp(p1,p2);
}
int main()
{
	int i=0,m=0,n=8,y=1;
	char x,a[30]={0};
	char **p1;char *p2;
	do
	{
		int y=1;
		x=getchar();
		while(x!=32&&y!=0)
		{
			if(x>='0'&&x<='9') 
			{
				a[m]=x;m++;
				if((x=getchar())==EOF){y=0;};
			}
			else 
			{
				a[n]=x;n++;
				if((x=getchar())==EOF){y=0;};
			}
		}
		if(y!=0)
		{
			p2=a;
			*(p1+i)=p2;
			i++;
		}
	}while(y!=0);
	qsort(p1,i,sizeof(char*),cmp);
	for(int j=0;j<i;j++)
	{
		printf("%s ",p1[j]);
	}
	return 0;
	
	
 } 