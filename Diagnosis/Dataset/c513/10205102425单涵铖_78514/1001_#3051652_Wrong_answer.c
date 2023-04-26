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
    int k;
    if(n<0)
    {
        res[0]='-';
        n=n*(-1);
        k=1;
        while(n!=0)
        {
            res[k]=table[n%r];
            k++;
            n=n/r;
        }
    }
    else
    {
        k=0;
        while(n!=0)
        {
            res[k]=table[n%r];
            k++;
            n=n/r;
        } 
    }
    printf("%s\n",res);
}

int main()
{
    int t,k=0;
    Data data;
    
    scanf("%d",&t);
    
    for(int i=0;i<t;i++)
    {
        scanf("%lld %d",&data.n,&data.r);
        change(data.n,data.r);
    }
    
    return 0;
}