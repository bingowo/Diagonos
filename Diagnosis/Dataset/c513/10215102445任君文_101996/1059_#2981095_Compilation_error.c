#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define M 1000
int gcd(int a, int b)
{
    if (b == 0)
        return b;
    else if (a % b == 0)
        return b;
    else
        gcd(b, a % b);
}
int main()
{
    int i,j,temp;
    int n,s;
    int a[M]={0},rain[M]={0};
    int lowest;
    int height;
    int res=0,fm=0,fz=0;
    scanf("%d%d",&n,&s);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    lowest=a[0];
    height=a[0];
    for(i=1;i<n;i++)
    {
        if(lowest>a[i])
        {
           lowest=a[i]; 
        }
        if(height<a[i])
        {
            height=a[i];
        }
    }
    for(j=lowest+1;j<height+1;j++)
    {
        for(i=0;i<n;i++)
        {
            if(a[i]<j)
            {
                rain[j]++;
            }
        }
    }
    res=lowest;
    while(s!=0)
    {
        if(rain[height]==0)
        {
            fm=n;
            if(s>=n)
            {
                s=s-n;
                res++;
            }
            else
            {
                fz=s;
                s=0;
                break;
            }
        }
        else
        {
            for(i=lowest+1;i<height+1;i++)
            {
                if(s>=rain[i])
                {
                    s=s-rain[i];
                    rain[i]=0;
                    res=i;
                }
                else
                {   fz=s;
                    s=0;
                    fm=rain[i];
                    break;
                }
            }
        }
    }
    temp=gcd(fz,fm)
    fz=fz/temp;
    fm=fm/temp;
    if(fz!=0)
    {
        if(res!=0)
        {printf("%d+%d/%d\n",res,fz,fm);}
        else
        {printf("%d/%d\n",fz,fm);}
    }
    else
    {
        printf("%d\n",res);
    }
    return 0;
}