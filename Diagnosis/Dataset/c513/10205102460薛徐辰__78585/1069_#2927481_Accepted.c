#include<stdio.h>
#include<malloc.h>
int getm(int n)
{
    int m=0,n1=n;
    while(n1>0)
    {
        m=m*10+n1%10;
        n1=n1/10;
    }
    return m;
}

int* solve(int n)
{
    int m=getm(n),a=0;
    int *ans;
    ans=(int*)malloc(100);
    while(n!=m)
    {
        n+=m;
        m=getm(n);
        a++;
    }
    ans[0]=a;
    ans[1]=n;
    return ans;
    free(ans);
}

int main()
{
    int n,*a;
    scanf("%d",&n);
    a=solve(n);
    printf("%d %d",a[0],a[1]);
    return 0;}