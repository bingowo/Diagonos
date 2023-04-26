#include <stdio.h>
#include <stdlib.h>
#include<string.h>
unsigned long long find(len,width){
    if (len<width) {unsigned m=len;len=width;width=m;}
    if (width==0) return 0;
    if (width==1) return len*4;
    return find(len-width,width)+width*4;
}
int main()
{   unsigned long long len,width;
    scanf("%llu%llu",&len,&width);
    printf("%llu\n",find(len,width));
    return 0;
}

