#include <stdio.h>
#include <stdlib.h>

int main()
{
    char s;
    int n[1001]={0};
    int i;
    while((scanf("%c",&s))!=EOF)
    {
        while((scanf("%d",&i))!=EOF) n[i]++;
    }
    if(s=='A')
    {
        for(i=0;i<=1000;i++)
        {
            if(n[i]>0) printf("%d ",i);
        }
    }
    else
    {
        for(i=1000;i>0;i--)
        {
            if(n[i]>0) printf("%d ",i);
        }
    }
    printf("\n");
    return 0;
}
