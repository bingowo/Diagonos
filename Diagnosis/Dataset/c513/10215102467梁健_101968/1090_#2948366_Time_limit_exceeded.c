#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
int main()
{
    unsigned long long a,res=1;
    while(scanf("%llu",&a)){
        if(a==0)break;
        for(int i=0;i<a;i++){
            res*=a;
        }
        while(res>10)res/=10;
        printf("%lld\n",res);
        res=1;
    }
}
