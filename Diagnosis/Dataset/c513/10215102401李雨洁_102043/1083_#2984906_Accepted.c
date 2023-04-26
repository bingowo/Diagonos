#include<stdio.h>

int main()
{
    int t;
    scanf("%d",&t);
    for(int z = 0; z < t; z++)
    {
        int n;
        scanf("%d",&n);
        printf("case #%d:\n",z);
        printf("%d\n",n/5+n/25+n/125+n/625);
    }
    return 0;
}




