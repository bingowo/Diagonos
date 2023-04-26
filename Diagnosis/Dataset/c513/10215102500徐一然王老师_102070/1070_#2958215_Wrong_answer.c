#include <stdio.h>
#include <math.h>


int Dic[21]={0};
int Dic1[21]={0,1,3,7};

int F(int n)
{
    if(Dic[n]!=0)
    {

        return Dic[n];
    }
    if(n==1)
    {
        return Dic[n]=0;
    }
    else if(n==2)
    {
        return Dic[n]=0;
    }
    else if(n==3)
    {
        Dic[n]=1;
        Dic1[n]=pow(2,n)-Dic[n];
        return Dic[n];
    }
    else
    {
        Dic[n]=F(n-1)+Dic1[n-2];
        Dic1[n]=pow(2,n)-Dic[n];
        return Dic[n];
    }
}

int main()
{
    int n=0;
    while(1)
    {
        scanf("%d",&n);
        if(n==-1)
            break;
        F(n);
        printf("%d",Dic1[n]);
    }
    return 0;
}
