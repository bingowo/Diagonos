#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int cmp1(const void* a,const void* b)
{
    return *(int*)a-*(int*)b;
}
int cmp2(const void* a,const void* b)
{
    return *(int*)b-*(int*)a;
}
int main()
{
    char a;
    int num[101],n=0;
    scanf("%c",&a);
    while(scanf("%d",&num[n])!=EOF)
    {
        n++;
    }
    if(a=='A')
    {
        qsort(num,n,sizeof(num[0]),cmp1);
    }
    else
    {
        qsort(num,n,sizeof(num[0]),cmp2);
    }
    for(int i=0;i<n;i++)
    {
        if(i==0 || (i!=0 && num[i]!=num[i-1]))
            printf("%d ",num[i]);
    }
    return 0;
}
