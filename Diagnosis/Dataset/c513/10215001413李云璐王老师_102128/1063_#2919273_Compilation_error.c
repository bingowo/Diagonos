#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int main()
{
    long long int x,y,chang,kuan;
    scanf("%lld%lld",&x,&y);
    chang=(x>y)?x:y;
    kuan=(x>y)?y:x;
    long long int v=0;
    while(chang!=kuan)
    {v+=4*kuan;
    chang=chang-kuan;
    long long int zhong;
    if(chang<kuan) {c=chang;chang=kuan;kuan=c;}
    }
    v+=4*kuan;
    printf("%lld",v);
    return 0;
}