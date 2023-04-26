#include <stdio.h>
#include <stdlib.h>

char table[36]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

typedef struct
{
    long long int n;
    int r;
}Data;

void change(long long int n,int r)
{
    char res[33];
    int k=0;
    if(n<0)
    {
        n=-n;
        while(n!=0)
        {
            res[k]=table[n%r];
            k++;
            n=n/r;
        }
        res[k-1]='-';
    }
    else
    {
        while(n!=0)
        {
            res[k]=table[n%r];
            k++;
            n=n/r;
        }
    }
    for(int i=k-1;i>-1;i--)
    {
        printf('%c',res[k]);
    }
}

int main()
{
    int t;
    Data data;

    scanf("%d",&t);

    for(int i=0;i<t;i++)
    {
        scanf("%lld %d",&data.n,&data.r);
        change(data.n,data.r);
        printf("\n");
    }

    return 0;
}