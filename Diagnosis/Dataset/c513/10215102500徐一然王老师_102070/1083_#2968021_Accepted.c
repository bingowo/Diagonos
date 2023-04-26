#include <stdio.h>



int main()
{
    int count,count1,n;
    scanf("%d",&count);
    count1=count;
    while(count--)
    {
        scanf("%d",&n);
        printf("case #%d:\n",count1-count-1);
        printf("%d\n",n/5+n/25+n/125+n/625);
    }
}
