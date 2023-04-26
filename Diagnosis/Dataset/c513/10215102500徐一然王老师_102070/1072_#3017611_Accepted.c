#include <stdio.h>
#include <math.h>

int panduan(long long int x,long long int y,int n)
{
    long long int sum;
    if(x<0)x=-x;
    if(y<0)y=-y;
    sum=x+y;
    if(sum<pow(2,n))
    {
        return 1;
    }
    else return 0;
}

int main()
{
    long long int x,y,sum,x1,y1;
    int n=1;
    scanf("%lld %lld",&x,&y);x1=x;y1=y;
    if(x<0)x=-x;
    if(y<0)y=-y;
    sum=x+y;
    if(x==0&&y==0)
    {
        printf("0");
        return 0;
    }
    else if((x+y)%2==0)
    {
        printf("-1");
        n=0;
    }

    while(n)
    {
        if(sum<pow(2,n))
        {
            break;
        }
        n++;
    }
    if(n!=0)printf("%d\n",n);
    int i=0;char S[100];
    if(n!=0)
    {
        while(n)
        {

            long long int tempw,tempe,tempn,temps;//printf("%lld %lld\n",x1,y1);
            tempw=x1-pow(2,n-1);//printf("!%lld\n",tempw);
            tempe=x1+pow(2,n-1);//printf("!!%lld\n",tempe);
            tempn=y1+pow(2,n-1);//printf("!!!%lld\n",tempn);
            temps=y1-pow(2,n-1);//printf("!!!!%lld\n",temps);
            n--;
            if(panduan(tempw,y1,n)){S[i]='E';i++;x1=tempw;}
            else if(panduan(tempe,y1,n)){S[i]='W';i++;x1=tempe;}
            else if(panduan(x1,tempn,n)){S[i]='S';i++;y1=tempn;}
            else if(panduan(x1,temps,n)){S[i]='N';i++;y1=temps;}
        }
    }

    for(int j=i-1;j>=0;j--)
        printf("%c",S[j]);
}
