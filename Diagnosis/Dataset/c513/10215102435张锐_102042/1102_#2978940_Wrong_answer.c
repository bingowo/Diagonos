#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    long long int n;
    scanf("%lld",&n);long long int num=0;
    int bushu=1;
    int a=0,b=0;
    for(int i=1;num<n;i++)
    {
        if(abs(n-num)<bushu)
        {
            if(i%4==1) b=b+abs(n-num);
            if(i%4==2) a=a-abs(n-num);
            if(i%4==3) b=b-abs(n-num);
            if(i%4==0) a=a+abs(n-num);
            break;
        }
        else
        {
            if(i%4==1) b=b+bushu,num+=bushu;
            if(i%4==2) a=a-bushu,num+=bushu,bushu++;
            if(i%4==3) b=b-bushu,num+=bushu;
            if(i%4==0) a=a+bushu,num+=bushu,bushu++;
        }

    }
    printf("(%d,%d)\n",a,b);
    return 0;
}
