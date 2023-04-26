#include<stdio.h>
#include<stdlib.h>
int number[1001];
int cmpA(const void* a,const void* b)
{
    return *((int*)a)-*((int*)b);
}
int cmpD(const void* a,const void* b)
{
    return *((int*)b)-*((int*)a);
}
int main()
{
    char c;
    int n=0;
    scanf("%c",&c);
    while(scanf("%d",number[n])!=EOF)
    {
        n++;
    }
    if(c=='A')qsort(number,n,sizeof(int),cmpA);
    else qsort(number,n,sizeof(int),cmpD);
    int i,num=number[0];
    printf("%d ",num);
    for(i=1;i<n;i++)
    {
        if(number[i]!=num)
        {
            num=number[i];
            printf("%d ",num);
        }
    }
    return 0;
}