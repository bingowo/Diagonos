#include <stdio.h>
#include <stdlib.h>

int main()
{
    int A,B,int0,mod,t,int1[25]={0},f[25]={0},i=0,j=0,len1,carry=0,len2,if0=0,if1=0,if2=0;
    scanf("%d %d",&A,&B);
    int0=A/B;
    mod=A-B*int0;
    while(int0!=0)
    {
        if2=1;
        t=int0%3;
        int0=int0/3;
        int1[i]=t;
        i++;
    }
    while(B!=1)
    {
        if1=1;
        B=B/3;
        if(mod>=B)
        {
            f[j]=mod/B;
            mod=mod-B;
        }
        else
            f[j]=0;
        j++;
    }
    len1=i;
    len2=j;
    for(i=len2-1;i>=0;i--)
    {
        if(f[i]+1+carry>=3)
        {
            f[i]=f[i]+1+carry-3;
            carry=1;
        }
        else
        {
            f[i]=f[i]+carry+1;
            carry=0;
        }
    }
    for(i=0;i<=len1;i++)
    {
        if(i==len1)
        {
            if(carry==1)
            {
                int1[i]=1;
                len1++;
                if0=1;
            }
            break;
        }
        if(int1[i]+1+carry>=3)
        {
            int1[i]=int1[i]+1+carry-3;
            carry=1;
        }
        else
        {
            int1[i]=int1[i]+carry+1;
            carry=0;
        }
    }
    for(i=len1-1;i>=0;i--)
    {
        if(i==len1-1&&if0)
            continue;
        int1[i]=int1[i]-1;
        if(int1[i]==-1)
        {
            int1[i]=2;
        }
    }
    for(i=0;i<len2;i++)
    {
        f[i]=f[i]-1;
        if(f[i]==-1)
        {
            f[i]=2;
        }
    }
    for(i=len1-1;i>=0;i--)
    {
        printf("%d",int1[i]);
    }
    if(!if2)
        printf("%d",0);
    if(if1)
        printf(".");
    for(i=0;i<len2;i++)
    {
        printf("%d",f[i]);
    }
    return 0;
}
