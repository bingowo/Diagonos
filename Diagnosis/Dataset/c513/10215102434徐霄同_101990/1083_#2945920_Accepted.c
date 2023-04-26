#include <stdio.h>

int main()
{
    int n,t,i,x;
    scanf("%d",&t);
    for(i=0;i<t;i++){
        scanf("%d",&n);
        x=n/5+n/25+n/125+n/625;
        printf("case #%d:\n",i);
        printf("%d\n",x);
    }
    return 0;
}
