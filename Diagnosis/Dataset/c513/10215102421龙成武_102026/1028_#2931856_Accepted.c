#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int comparA(const void *p1, const void *p2);
int comparD(const void *p1, const void *p2);
int main()
{
    int a[1000],i=0,len;
    char c;
    scanf("%c",&c);
    while(scanf("%d",&a[i])!=EOF)       //a中有i个元素
        i++;
    len=i;
    if(c=='A')
        qsort(a,len,sizeof(int),comparA);
    else
        qsort(a,len,sizeof(int),comparD);
    for(i=0;i<len;i++)
    {
        if(a[i+1]==a[i])
        {
            a[i]=0;
        }
    }
    for(i=0;i<len;i++)
    {
        if(a[i]!=0)
        {
            printf("%d ",a[i]);
        }
    }

    return 0;
}
int comparA(const void *p1, const void *p2)
{
    int *a,*b,flag=0;
    a=(int*)p1;
    b=(int*)p2;
    if(*a<*b)
        flag=-1;
    else
        flag=1;
    return flag;
}
int comparD(const void *p1, const void *p2)
{
    return -comparA(p1,p2);
}
