#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long n,i,cun=6,x,y,sum=0,st,shang,zuo,xia,you;
    scanf("%lld",&n);
    for(i=0;;i++)
    {
        sum+=cun;
        if(n<=sum) break;
        cun+=8;
    }
    st=sum-cun;
    x=i;
    y=-i;
    shang=i*2+1;
    zuo=shang;
    xia=shang+1;
    you=xia;

    if(st+shang>=n)
    {
        y+=(n-st);
    }
    else
    {
        st+=shang;
        y+=shang;
        if((st+zuo)>=n)
        {
            x-=(n-st);
        }
        else
        {
            st+=zuo;
            x-=zuo;
            if((st+xia)>=n)
            {
                y-=(n-st);
            }
            else
            {
                st+=xia;
                y-=xia;
                x+=(n-st);
            }

        }
    }

    printf("(%lld,%lld)\n",x,y);

}
