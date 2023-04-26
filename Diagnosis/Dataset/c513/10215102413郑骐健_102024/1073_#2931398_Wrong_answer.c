#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

long long po(long long a,int n)
{
    long long q =1;
    for(int i =0;i<n;i++)
    {
        q*=a;
    }
    return q;
}
long long good(long long a,long long b)
{
    long long a_ = a;
    long long b_ = b;
    long long k =0;
    int n1 = 0,n2 = 0;
    while(a_/10 !=0 )
    {
        n1+=1;
        a_/=10;
    }
     while(b_/10 !=0 )
    {
        n2+=1;
        b_/=10;
    }
    if(n1 ==n2)
    {
        if( a==po(10,n1)&&b == po(10,n2+1)-1)return po(8,n2+1);
        else if(a -b == po(10,n1)-1)return po(8,n1);

        else if(b - a<=10)
        {
            for(int i=0;i<=b-a;i++)
            {
             if((a+i)%9!=0&&((a+i)%10!=9))k+=1;
            }
        }
        else
        {
            for(int g = 1;g<9;g++)
            {
                if((g+1)*po(10,n1)>b)
                {
                    k+= good(0,b-g*po(10,n1)+1);  //  这里出错了
                    break;
                }
                else k+= good(g*po(10,n1),(g+1)*(po(10,n1))-1);
            }
        }

    }
    else
    {
        for(int i =n1;i < n2;i++)
        {
            if(i == 0)k += good(0,po(10,i+1)-1);
            else k += good(po(10,i),po(10,i+1)-1);
        }
        k+= good(po(10,n2),b);
    }
    return k;
}


int main()
{
    long long a,b;
    scanf("%lld%lld",&a,&b);
    long long k=0;
    k +=good(0,b);
    k=k-good(0,a)+1;
    printf("%lld",k);
    return 0;
}
