#include<stdio.h>
int main()
{
    int k,n,s=2;
    scanf("%d %d",&k,&n);
    if(n==1) s=0;
    if(n==2) s=1;
    else
    {
        for(int i=0;i<n-2;i++)
        {
            s*=2;
        }
    }
    printf("%d",s);
    return 0;
}