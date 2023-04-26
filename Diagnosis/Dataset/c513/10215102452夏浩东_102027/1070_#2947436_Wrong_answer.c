#include <stdio.h>
int func(int len)
{
    if(len==3) return 7;
    else if(len==2) return 4;
    else if(len==1) return 2;
    else if(len==0) return 1;
    else return 2*func(len-1)-func(len-3);
}
int main()
{
    int len=0;
    while(1)
    {
        scanf("%d",&len);
        if(len==-1) break;
        int res=func(len);
        printf("%d\n",res);
    }
    return 0;
}