#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<ctype.h>
//#include "myh.h"

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int x,y,a[101]={0},k=1;
        scanf("%d%d",&x,&y);
        printf("case #%d:\n0.",i);
        while(x>0)
        {
           printf("%d",x*10/y);
           x=x*10%y;
           if(a[x])break;
           a[x]=k++;
        }
        if(x)printf("\n%d-%d",a[x]+1,k);
        printf("\n");
    }
}
