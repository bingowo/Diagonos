#include <stdio.h>
#include <stdlib.h>
int f(int k,int n)
{
    int i,sum=0;
    if(n==1) return 0;
    if(n==2) return 1;
    switch(k)
    {
        case 3:
            if(n==3) return 1;
        case 4:
            if(n==3) return 1;
            if(n==4) return 2;
        case 5:
            if(n==3) return 1;
            if(n==4) return 2;
            if(n==5) return 4;
        case 6:
            if(n==3) return 1;
            if(n==4) return 2;
            if(n==5) return 4;
            if(n==6) return 8;
        case 7:
            if(n==3) return 1;
            if(n==4) return 2;
            if(n==5) return 4;
            if(n==6) return 8;
            if(n==7) return 16;
        case 8:
            if(n==3) return 1;
            if(n==4) return 2;
            if(n==5) return 4;
            if(n==6) return 8;
            if(n==7) return 16;
            if(n==8) return 32;
        case 9:
            if(n==3) return 1;
            if(n==4) return 2;
            if(n==5) return 4;
            if(n==6) return 8;
            if(n==7) return 16;
            if(n==8) return 32;
            if(n==9) return 64;
        case 10:
            if(n==3) return 1;
            if(n==4) return 2;
            if(n==5) return 4;
            if(n==6) return 8;
            if(n==7) return 16;
            if(n==8) return 32;
            if(n==9) return 64;
            if(n==10) return 128;
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
    int sum;
    sum=f(k,n);
    printf("%d",sum);
    return 0;
}
