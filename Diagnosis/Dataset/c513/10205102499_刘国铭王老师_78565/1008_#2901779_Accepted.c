#include <stdio.h>
#include <stdlib.h>


int getbinary(int bi[],int n)
{
    int i=0;
    while(n)
    {
        bi[i]=n%2;
        n/=2;
        i++;
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        int res=0;
        int bix[33]={0},biy[33]={0};
        getbinary(bix,x);
        getbinary(biy,y);
        for(int j=0;j<33;j++)
        {
            if(bix[j]!=biy[j])
                res++;
        }
        printf("%d\n",res);
    }
    return 0;
}
