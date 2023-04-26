#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp1(const void *a1,const void *b1)
{
    int a=*(int*)a1;
    int b=*(int*)b1;
    if(a!=b) return a-b;
}

int cmp2(const void *a1,const void *b1)
{
    int a=*(int*)a1;
    int b=*(int*)b1;
    if(a!=b) return b-a;
}

int main()
{

    char s;
    scanf("%s",&s);
    int a[105]= {0};
    int x=0;
    for(int i=0;; i++)
    {
        scanf("%d",&a[i]);
        x+=1;
        if(getchar()=='\n')break;//回车中断
    }
    //printf("%d\n",x);

    if(s=='A') qsort(a,x,sizeof(a[0]),cmp1);
    else qsort(a,x,sizeof(a[0]),cmp2);

    printf("%d",a[0]);
    for(int i=1;i<x;i++)
    {
        if(a[i]!=a[i-1]) printf(" %d",a[i]);
    }
    return 0;
}



