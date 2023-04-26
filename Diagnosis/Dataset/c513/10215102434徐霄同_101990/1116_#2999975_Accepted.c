#include <stdio.h>
#include <stdlib.h>
int main()
{
    long long x,y,n,s;
    scanf("%lld%lld",&x,&y);
    s=labs(x)+labs(y);
    if(s!=0&&s%2==0)
        printf("-1\n");
    else{
        n=0;
        while(s>1){
            if(s%4==1){
                s=(s+1)/2;
                n++;
            }
            else if(s%4==3){
                s=(s-1)/2;
                n++;
            }
        }
        if(s==1)
            n++;
        printf("%lld\n",n);
    }
    return 0;
}
