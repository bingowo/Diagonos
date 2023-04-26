#include <stdio.h>
#include <stdlib.h>

int f(int a)
{
    int ans=1;
    if(a<0) a=-a;
    while(a!=1)
    {
        ans++;
        a/=10;
    }
    return ans;

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
