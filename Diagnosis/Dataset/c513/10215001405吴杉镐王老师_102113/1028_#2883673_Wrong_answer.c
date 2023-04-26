#include <stdio.h>
#include <stdlib.h>

int cmp1(const void* a,const void* b) 
{
    int m=*(int*)a;
    int n=*(int*)b;
    if(a<=b) return -1;
    else return 1;
}

int cmp2(const void* a,const void* b) 
{
    int m=*(int*)a;
    int n=*(int*)b;
    if(a<=b) return 1;
    else return -1;
}

int main()
{
    char c;
    scanf("%c",&c);
    int res[101]={'\0'};
    int i=0;
    for(i=0;scanf("%d",&res[i])!=EOF;i++)
	{
		for(int k=0;k<i;k++)
		{
			if(res[k]==res[i])
			{
				res[i]='\0';
				i--;
				break;
			}
		}
	} 
    if(c=='D')
        qsort(res,i,sizeof(res[0]),cmp2);
    else
        qsort(res,i,sizeof(res[0]),cmp1);
    int ans=res[0];
    printf("%d",ans);
    for(int j=1;res[j]!='\0';j++)
    {
        printf(" %d",res[j]);
    }
    return 0;
}