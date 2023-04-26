#include<stdio.h>
int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        int n;
        scanf("%d",&n);
        printf("case #%d:\n%d\n",i,n/5+n/25+n/125+n/625);
        
        
    }
    
    return 0;
}