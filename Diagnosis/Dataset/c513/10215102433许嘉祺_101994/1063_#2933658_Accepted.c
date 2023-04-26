#include <stdio.h>
#include <stdlib.h>
#include<string.h>
unsigned long long find(unsigned long long len,unsigned long long width){
    if (len<width) {unsigned long long m=len;len=width;width=m;}
    if (width==0) return 0;
    if (width==1) return len*4;
    return find(width,len%width)+width*4*(len/width);
}
int main()
{   unsigned long long len,width;
    scanf("%llu%llu",&len,&width);
    printf("%llu\n",find(len,width));
    return 0;
}
