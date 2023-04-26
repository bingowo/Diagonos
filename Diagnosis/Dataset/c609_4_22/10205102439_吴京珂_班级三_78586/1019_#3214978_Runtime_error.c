#include <stdio.h>
#include <stdlib.h>

int f(int n)
{
    int ans=0;
    if(n<0) n=-n;
    for(int i=0;i<100;i++)
    {
        ans++;
        if(n<10){return ans;}
        n/=10;
    }

}

int cmp(const void *a1,const void *b1)//比较函数
{
    int a=*(int*)a1;
    int b=*(int*)b1;
    if(f(a)>f(b)) return -1;
    else if(f(a)<f(b)) return 1;
    else
    {
        if(a<b) return -1;
        else return 1;
    }
}

int main()
{
    int a[100005]= {0};
    int x=0;
    for(int i=0;; i++)
    {
        scanf("%d",&a[i]);
        x+=1;
        if(getchar()=='\n')break;//回车中断
    }

    qsort(a,x,sizeof(a[0]),cmp);
    printf("%d",a[0]);
    for(int i=1;i<x;i++)
    {
        printf(" %d",a[i]);
    }

    return 0;
}
