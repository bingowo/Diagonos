#include<stdio.h>
#include<stdlib.h>
int number(int num)
{
    if(num==1)
        return 2;
    else if(num==2)
        return 4;
    else if(num==3)
        return 7;
    else if(num==4)
        return 12;
    else 
        return (2*number(num-1)-number(n-2)+number(n-3));
}
int main()
{
    int n=0;
    int res=0;
    while(n!=-1)
    {
        scanf("%d",&n);
        res=number(n);
        printf("%d\n",res);
    }
    return 0;
}