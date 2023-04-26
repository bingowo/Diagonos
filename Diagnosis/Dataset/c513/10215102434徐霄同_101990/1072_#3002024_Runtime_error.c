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
void f(long long x,long long y)
{
    long long s,n,a;
    s=labs(x)+labs(y);
    if(s==0)
        return;
    n=step(s);
    a=1<<(n-1);
    if(labs(x)>labs(y)){
        if(x>0){
            x=x-a;
            ans[strlen(ans)]='E';
        }
        else{
            x=x+a;
            ans[strlen(ans)]='W';
        }
    }
    else{
        if(y>0){
            y=y-a;
            ans[strlen(ans)]='N';
        }
        else{
            y=y+a;
            ans[strlen(ans)]='S';
        }
    }
    f(x,y);
}
int main()
{
    long long x,y,n,i,s;
    scanf("%lld%lld",&x,&y);
    s=labs(x)+labs(y);
    if(s!=0&&s%2==0)
        printf("-1\n");
    else{
        n=step(s);
        printf("%lld\n",n);
        memset(ans,0,sizeof(ans));
        f(x,y);
        if(strlen(ans)>0){
            for(i=strlen(ans)-1;i>=0;i--)
                printf("%c",ans[i]);
            printf("\n");
        }
    }
    return 0;
}
