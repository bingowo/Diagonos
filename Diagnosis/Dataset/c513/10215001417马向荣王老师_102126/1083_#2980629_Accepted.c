#include<stdio.h>
int main()
{
    int a,b;
    scanf("%d",&a);
    for(b=0;b<a;b++)
    {
        printf("case #%d:\n",b);
        int n;
        scanf("%d",&n);
        printf("%d\n",n/5+n/25+n/125+n/625);
    }
    return 0;
}