#include <stdio.h>
#include <math.h>


int Dic[21]={0};
int Dic1[21]={0,2,3,5};

int F(int n)
{
    if(Dic[n]!=0)
    {

        return Dic[n];
    }
    if(n==1)
    {
        return Dic[n]=2;
    }
    else if(n==2)
    {
        return Dic[n]=4;
    }
    else if(n==3)
    {
        Dic[n]=1;
        return Dic[n];
    }
    else
    {
        Dic[n]=F(n-1)*2+pow(2,n-2)-Dic[n-2]-pow(2,n-3)+Dic[n-3];
        return Dic[n];
    }
}

int main()
{
    int n=0,ans=0;
    while(1)
    {
        scanf("%d",&n);
        if(n==-1)
            break;
        if(n==1)
        {
            printf("2\n");
        }
        else if(n==2)
        {
            printf("4\n");
        }
        else
        {
            F(n);
            ans=pow(2,n)-Dic[n];
            printf("%d\n",ans);
        }

    }
    return 0;
}
