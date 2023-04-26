#include <stdio.h>
#include <stdlib.h>
long long unsigned s(long long int x,long long int y)
{
    long long unsigned res=x%y,num=x/y;
    if(res==0) return 4*y*num;
    else return 4*y*num+s(y,res);
}
int main()
{
    long long unsigned x,y;
    scanf("%llu%llu",&x,&y);
    long long unsigned ans=s(x,y);
    printf("%llu\n",ans);
    return 0;
}
