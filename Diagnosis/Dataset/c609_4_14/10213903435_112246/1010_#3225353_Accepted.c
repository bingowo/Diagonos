#include <stdio.h>
#include <stdlib.h>
int main()
{
    int num,base,i=0;
    scanf("%d%d",&num,&base);
    char rslt[20];
    do
    {
        char c=num%base;
        if(c>=0)num/=base;
        else if(c<0){c=num-(num/base+1)*base;num=num/base+1;}
        if(c>=10){c=c+'A'-10;}
        rslt[i++]=c;
    }while(num);
    for(;i;i--)
    {
        if(rslt[i-1]>=10)printf("%c",rslt[i-1]);
        else printf("%d",rslt[i-1]);
    }
    return 0;
}
