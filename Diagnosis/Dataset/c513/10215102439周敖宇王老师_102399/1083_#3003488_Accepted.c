#include<stdio.h>
int main()
{
    int T,i,j,n,cnt=0;
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        scanf("%d",&n);
        printf("case #%d:\n%d\n",i,n/5+n/25+n/125+n/625);
    }
    return 0;
}