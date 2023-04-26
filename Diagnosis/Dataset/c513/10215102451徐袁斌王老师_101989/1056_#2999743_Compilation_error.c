#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
struct s
{
	char a[15];
	int b;
};
int cmp(const void *a,const void *b)
{
	struct s* A=(struct s*)a;
	struct s* B=(struct s*)b;
	if(A->b!=B->b) return (B->b)-(A->b);
	else return strcmp(A->a,B->a);
}
int main()
{
    int t,len;
    s x[4000];
    char b[5001],c[15];
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
		scanf("%s",x[i].a);
		x[i].b=strlen(x[i].a);
	}
	qsort(x,t,sizeof(x[0]),cmp);
	scanf("%s",b);
	len=strlen(b);
	for(int i=0;i<len;i++)
	{
		for(int j=x[0].b;j>0;j--)
		{
			int o=0,d=0;while(x[o].b>j) o++;
			for(int k=o;x[k].b>=j;k++)
			{
				strncpy(c,b+i,j);
				c[j]='\0';
				if(strcmp(c,x[k].a)==0){printf("%s ",c);d=1;}
			}
			if(d==1){i+=j-1;break;}
			else if(j==1) {printf("%c ",b[i]);}
		}
	}
}