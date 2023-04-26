#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
long long a=0,b=0,step=1;
int time = 0;
void solve(long long x,long long y)
{
    
    step*=2;
    time++;
    if(a==x&&b==y)solve(x,y);
    else printf("%d",time);
}
int main()
{
    long long x,y;scanf("%lld %lld",&x,&y);
    if(x==0&&y==0)printf("0");
    else if(x%2&&y%2)printf("-1");
    else if(x%2==0&&y%2==0)printf("-1");
    else{
        
    }
    return 0;
}
