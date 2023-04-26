#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long int x=0,y=0;
    scanf("%lld %lld",&x,&y);
    long long int sum=llabs(x)+llabs(y);
    if(sum%2==0) printf("-1\n");
    else{
        int n=1;
        while(sum/2>0){
            n++;
            sum/=2;
        }
        printf("%d\n",n);
    }
    return 0;
}
