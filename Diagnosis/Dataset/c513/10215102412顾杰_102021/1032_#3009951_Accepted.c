#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<ctype.h>
//#include "myh.h"
int cmp(const void*a,const void*b)
{
    int *pa=(int*)a,*pb=(int*)b,i;
    for(i=0;pa[i]==pb[i];i++);//printf("pai=%d,pbi=%d\n",pa[i],pb[i]);
    //printf("!%d\n",i);
    return pa[i]>pb[i]?-1:1;
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int m,t,a[1000][51]={0};
        scanf("%d",&m);
        for(int j=0;j<m;j++)
        {
            int k=0;
            while(1)
            {
                scanf("%d",&t);
                a[j][k++]=t;
                if(t==-1)break;
            }
        }
        qsort(a,m,sizeof(a[0]),cmp);
        for(int j=0;j<m;j++){for(int k=0;a[j][k]!=-1;k++)printf("%d ",a[j][k]);printf("\n");}
    }
}
