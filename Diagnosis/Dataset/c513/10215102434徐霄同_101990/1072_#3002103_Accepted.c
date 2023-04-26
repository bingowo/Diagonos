#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char ans[100];
long long step(long long s)
{
    long long x,n;
    x=s;n=0;
    while(x>1){
        if(x%4==1){
            x=(x+1)/2;
            n++;
        }
        else if(x%4==3){
            x=(x-1)/2;
            n++;
        }
    }
    if(x==1)
        n++;
    return n;
}
void f(long long x,long long y,long long n)
{
    long long a;
    if(n==0)
        return;
    a=(long long)1<<(n-1);
    if(llabs(x)>llabs(y)){
        if(x>0){
            f(x-a,y,n-1);
            printf("E");
        }
        else{
            f(x+a,y,n-1);
            printf("W");
        }
    }
    else{
        if(y>0){
            f(x,y-a,n-1);
            printf("N");
        }
        else{
            f(x,y+a,n-1);
            printf("S");
        }
    }
}
int main()
{
    long long x,y,n,i,s;
    scanf("%lld%lld",&x,&y);
    s=llabs(x)+llabs(y);
    if(s!=0&&s%2==0)
        printf("-1\n");
    else{
        n=step(s);
        printf("%lld\n",n);
        memset(ans,0,sizeof(ans));
        f(x,y,n);
        if(n>0)
            printf("\n");
    }
    return 0;
}
