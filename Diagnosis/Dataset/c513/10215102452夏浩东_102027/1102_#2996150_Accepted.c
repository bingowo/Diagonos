#include <stdio.h>
int main()
{
    long long int num=0;
    long long int x=0,y=0; 
    scanf("%lld",&num);
    long long int mm=0,k=0;
    for(k=1;mm<=(num-1)/8;k++) mm+=k;
    long long int denth = mm*8-num;
    long long int len = 2*(k-1);
    if(denth<=len) {x=len/2;y=len/2-denth;}
    else if(denth<=len*2){x=len/2-denth+len;y=-len/2;}
    else if(denth<=len*3){x=-len/2;y=-len/2+denth-2*len;}
    else {x=-len/2+denth-len*3;y=len/2;}
    if(num==0) x=y=0;
    printf("(%lld,%lld)",x,y);
    return 0;
}