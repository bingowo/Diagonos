#include <stdio.h>
#include <stdlib.h>


int main()
{
    int n=0,i,al=0,lo=1,flag;
    int w[51];
    char c;
    while(scanf("%c",&c)!=EOF)
    {
        if(c=='-')
            w[n]=1;
        else
            w[n]=2;
        n++;
    }
    flag=w[0];
    for(i=0;i<n;i++)
    {
        if(w[i]!=flag)
        {
            lo++;
            flag=w[i];
        }
        else
        {
            if(lo>al)
            {
                al=lo;
            }
            lo=1;
        }
    }
    if(lo>al)
    {
        al=lo;
    }
    printf("%d",al);
    return 0;
}
