#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main()
{
    int d;char str[10];int k,sign;float num=1.123;
    str=fcvt(num,3,&k,&sign);
    printf("%s %d %d",str,k,sign);
}
