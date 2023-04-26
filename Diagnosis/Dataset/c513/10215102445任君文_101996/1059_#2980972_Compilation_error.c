#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define M 1000
int main()
{
    int i,j;
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
            hright=a[i];
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
            res=height;
            fm=n;
            if(s>=n)
            {
                s=s-n;
                res++;
            }
            else
            {
                fz=s;
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
                    fm=rain[i];
                    break;
                }
            }
        }
    }
    if(fz!=0)
    {
        printf("%d+%d/%d",res,fz,fm);
    }
    else
    {
        printf("%d",res);
    }
    return 0;
}