#include<stdio.h>
long long int f(int h)
{
    if(h==1)return 1;
    if(h==2)return 2;
    if(h==3)return 4;
    if(h==4)return 8;
    if(h==5)return 15;
    return 2*f(h-1)-f(h-5);
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int t;
        scanf("%d",&t);
        long long int b;
        b=f(t);
        printf("case #%d:\n",i);
        printf("%lld\n",b);
    }
    return 0;
}
