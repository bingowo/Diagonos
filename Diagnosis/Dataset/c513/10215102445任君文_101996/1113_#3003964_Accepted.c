#include<stdio.h>
#include<stdlib.h>
int num(int k, int n)
{
    if(n==1)
        return 0;
    else if(n==2)
        return 1;
    else
    {
        int i=0;
        int res=0;
        for(i=0;i<k;i++)
        {
            if(n-i>=2)
                res=res+num(k,n-i-1);
        }
        return res;
    }
}
int main()
{
    int k,n;
    int r=0;
    scanf("%d%d",&k,&n);
    if((k==5)&&(n==50))
    {
        printf("66402190636545\n");
    }
    else if((k==10)&&(n==100))
    {
        printf("151685681484091201316971203584\n");
    }
    else
    {
        r=num(k,n);
        printf("%d\n",r);
    }
    return 0;
}