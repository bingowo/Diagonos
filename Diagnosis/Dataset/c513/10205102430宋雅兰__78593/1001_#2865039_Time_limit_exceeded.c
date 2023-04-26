#include<stdio.h>
int func(int n,int r)
{
    if(n<0){
        n=-n;
        printf("-");
    }
    int t;
    while(n)
    {
        func(n/r,r);
        t=n%r;
        if(t>=10)
            t=t-10+'A';
        else t=t+'0';
        printf("%c",t);
    }
    return 0;
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        int N,R;
        scanf("%d%d",&N,&R);
        func(N,R);
        printf("\n");
    }
    return 0;
}