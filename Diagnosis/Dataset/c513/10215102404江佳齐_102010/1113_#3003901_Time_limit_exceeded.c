#include <stdio.h>
#include <stdlib.h>
long long int f(int k,int n)
{
    int i;
    long long int sum=0;
    if(n==1) return 0;
    if(n==2) return 1;
    switch(k)
    {
        case 3:
            if(n==3) return 1;
            break;
        case 4:
            if(n==3) return 1;
            if(n==4) return 2;
            break;
        case 5:
            if(n==3) return 1;
            if(n==4) return 2;
            if(n==5) return 4;
            break;
        case 6:
            if(n==3) return 1;
            if(n==4) return 2;
            if(n==5) return 4;
            if(n==6) return 8;
            break;
        case 7:
            if(n==3) return 1;
            if(n==4) return 2;
            if(n==5) return 4;
            if(n==6) return 8;
            if(n==7) return 16;
            break;
        case 8:
            if(n==3) return 1;
            if(n==4) return 2;
            if(n==5) return 4;
            if(n==6) return 8;
            if(n==7) return 16;
            if(n==8) return 32;
            break;
        case 9:
            if(n==3) return 1;
            if(n==4) return 2;
            if(n==5) return 4;
            if(n==6) return 8;
            if(n==7) return 16;
            if(n==8) return 32;
            if(n==9) return 64;
            break;
        case 10:
            if(n==3) return 1;
            if(n==4) return 2;
            if(n==5) return 4;
            if(n==6) return 8;
            if(n==7) return 16;
            if(n==8) return 32;
            if(n==9) return 64;
            if(n==10) return 128;
            break;
    }
    for(i=1;i<=k;i++)
    {
        sum+=f(k,n-i);
    }
    return sum;
}
int main()
{
    int k,n;
    scanf("%d %d",&k,&n);
    long long int sum;
    sum=f(k,n);
    printf("%lld",sum);
    return 0;
}
