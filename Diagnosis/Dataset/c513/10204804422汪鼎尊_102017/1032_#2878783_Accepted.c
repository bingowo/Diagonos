#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int cmp(const void *a,const void *b)
{
	const int *i1=(int*)a,*i2=(int*)b;
	while(*i1==*i2&&*i1!=-1&&*i2!=-1)
	{
		i1++;i2++;
	}
	return *i2-*i1;
}

int main()
{
	int i,j=0,k;
	int len=0;
	int c,cases;
	int line[1000][51];
	scanf("%d",&cases);
	for(c=0;c<cases;c++)
	{
		scanf("%d",&len);
		for(i=0;i<len;i++)
		{
			j=0;
			while(1)
			{
				scanf("%d",&line[i][j]);
				if(line[i][j]==-1)break;
				j++;
			}
		}
		qsort(line,len,51*sizeof(int),cmp);
		//printf("case #%d:\n",c);
		for(i=0;i<len;i++)for(j=0;line[i][j]!=-1;j++)printf("%d%c",line[i][j],line[i][j+1]==-1?'\n':' ');
		//if(c!=cases-1)putchar('\n');
	}
	return 0;
}