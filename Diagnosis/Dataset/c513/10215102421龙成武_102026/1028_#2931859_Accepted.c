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
    while(scanf("%d",&a[i])!=EOF)       //a中有i个元素  //不指定元素个数都会键入EOF的
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
            printf("%d ",a[i]);     //经验公式，虽然说输出格式要求最后一个数字没有空格，但是有空格它也会通过，考试时就不要太纠结这个，提交先
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
