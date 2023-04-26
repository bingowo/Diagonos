#include <stdio.h>
#include <stdlib.h>
// |||-||--|--|---|-||-|-|-|--||---||-||-||-|--||

int main()
{
    int n=0,i,al=0,lo=0,flag;
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
    for(i=0;i<n;i++)
    {
        if(lo==0)
        {
            flag=w[i];
            lo++;
            continue;
        }
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
            lo=0;
        }
    }
    printf("%d",al);
    return 0;
}
