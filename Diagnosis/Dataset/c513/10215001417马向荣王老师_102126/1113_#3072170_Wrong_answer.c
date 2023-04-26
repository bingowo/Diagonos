#include<stdio.h>
int main()
{
    int k,n,s=0;
    scanf("%d %d",&k,&n);
    if(n==1) s=0;
    if(n==2) s=1;
    printf("%d",s);
    return 0;
}