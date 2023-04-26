#include <stdio.h>
#include <stdlib.h>

int cmp1(const void* a,const void* b)
{
    int* ap=(int*)a;
    int* bp=(int*)b;
    return (*ap-*bp);
}

int cmp2(const void* a,const void* b)
{
    int* ap=(int*)a;
    int* bp=(int*)b;
    return (*bp-*ap);
}

int main()
{
    char c;
    int i=0,j,k=0;
    scanf("%c",&c);
    int a[150]={0};//存储输入的数字
    int d[1000]={0};//判断是否重复的数字
    int b[150]={0};//存储最后没有重复的输入的数字
    do
    {
        scanf("%d",&a[i]);i++;
    }
    while(getchar()!='\n');
    for(j=0;j<i;j++)
    {
        if(d[a[j]]==0)
        {
            d[a[j]]=1;
            b[k++]=a[j];
        }
    }
    if(c=='A')
        qsort(b,k,sizeof(int),cmp1);
    else
        qsort(b,k,sizeof(int),cmp2);
    for(i=0;i<k;i++)
        printf("%d ",b[i]);
}
