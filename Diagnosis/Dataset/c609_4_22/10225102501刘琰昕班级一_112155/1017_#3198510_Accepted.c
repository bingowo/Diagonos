#include <stdio.h>
#include <stdlib.h>

int a[101]={0};

int cmpup(const void* a,const void* b)
{return (*(int*)a-*(int*)b);}

int cmpdown(const void* a,const void* b)
{return (*(int*)b-*(int*)a);}

int main()
{
	int n=0;char mode,c;
    scanf("%c",&mode);
    while(1)
    {
        scanf("%d",&a[n]);
        n++;
        c=getchar();
        if(c!=' ')break;
    }

    if(mode=='A')qsort(a,n,sizeof(a[0]),cmpup);
    else qsort(a,n,sizeof(a[0]),cmpdown);
    printf("%d",a[0]);
    for(int i=1;i<n;i++)
    {if(a[i]!=a[i-1])printf(" %d",a[i]);}
	return 0;
}