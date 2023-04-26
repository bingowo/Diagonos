#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void PATH(long long int x,long long int y,int k);

int main()
{
    long long int x,y;
    scanf("%lld %lld",&x,&y);
    if((llabs(x)+llabs(y))%2==0&&(x!=0||y!=0))
    {
        printf("-1\n");
    }
    else if(x==0&&y==0)
    {
        printf("0\n");
    }
    else
    {
        double mid=log2((llabs(x)+llabs(y)+1)*1.0);
        int k=(int)(ceil(mid));
        printf("%d\n",k);
        PATH(x,y,k);
    }
}
void PATH(long long int x,long long int y,int k)
{
    if(k)
    {
        long long d=(1LL<<(k-1));
        if(llabs(x)>llabs(y))
        {
            if(x>0){PATH(x-d,y,k-1);printf("E");}
            else{PATH(x+d,y,k-1);printf("W");}
        }
        else
        {
            if(y>0){PATH(x,y-d,k-1);printf("N");}
            else{PATH(x,y+d,k-1);printf("S");}
        }
    }
}

