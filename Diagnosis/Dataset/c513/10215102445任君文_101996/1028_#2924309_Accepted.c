#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 1000
int main()
{
    char c;
    int i=0,j=0,temp,MAX=1,MIN=1000;
    int n[N]={0},t[N]={0};
    scanf("%c",&c);
    while((scanf("%d",&n[i]))!=EOF)
    {
        i++;
    }
    for(j=0;j<i;j++)
    {
        temp=n[j];
        if(temp>MAX)
            MAX=temp;
        if(temp<MIN)
            MIN=temp;
        t[temp]++;
    }
    if(c=='A')
    {
        for(j=MIN;j<MAX;j++)
        {
            if(t[j]!=0)
            {
                printf("%d ",j);
            }
        }
        printf("%d\n",MAX);
    }
    if(c=='D')
    {
        for(j=MAX;j>MIN;j--)
        {
            if(t[j]!=0)
            {
                printf("%d ",j);
            }
        }
        printf("%d\n",MIN);
    }
    return 0;
}