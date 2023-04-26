#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int main()
{
    int x,y;
    int a,b,c;
    int s[60];
    int s1[60];
    scanf("%d%d",&x,&y);
    memset(s,0,sizeof(s));
    memset(s1,0,sizeof(s));
    if (y==1)
    {
        a=x;
        int i=0;
        while (a>0)
        {
            s[i]=a%3;
            a=a/3;
            i++;
        }
        for (int j=0; j<i; j++)
        {
            s[j]=s[j]+1;
            if (s[j]>=3)
            {
                s[j+1]=s[j+1]+s[j]/3;
                s[j]=s[j]%3;

            }
        }

        if (s[i]>0)
        {
            s[i]=s[i]+1;
            i=i+1;
        }
        for (int j=0; j<i; j++)
        {
            s[j]=s[j]-1;
            if(s[j]<0) s[j]=2;
        }
        for (int j=i-1; j>=0; j--)
            printf("%d",s[j]);
        if(i==0) printf("0");
    }
    else
    {
        a=x/y;
        b=x%y;
        c=y;
        int n=0;
        int i=0;
        while (a>0)
        {
            s[i]=a%3;
            a=a/3;
            i++;
        }
        if (i==0) i=1;
        while (b>0)
        {
            c=c/3;
            s1[n]=b/c;
            b=b%c;
            n++;

        }
        for (int j=n-1;j>0;j--)
        {
            s1[j]=s1[j]+1;
            if (s1[j]>=3)
            {
                s1[j-1]=s1[j-1]+s1[j]/3;
                s1[j]=s1[j]%3;

            }
        }
        s1[0]+=1;
        if (s1[0]>=3) {s1[0]=s1[0]%3;s[0]+=1;}
        for (int j=0; j<i; j++)
        {
            s[j]=s[j]+1;
            if (s[j]>=3)
            {
                s[j+1]=s[j+1]+s[j]/3;
                s[j]=s[j]%3;

            }
        }
        if (s[i]>0)
        {
            s[i]=s[i]+1;
            i=i+1;
        }
        for (int j=0; j<i; j++)
        {
            s[j]=s[j]-1;
            if(s[j]<0) s[j]=2;
        }
        for (int j=0; j<n; j++)
        {
            s1[j]=s1[j]-1;
            if(s1[j]<0) s1[j]=2;
        }
        for (int j=i-1; j>=0; j--)
            printf("%d",s[j]);
            printf(".");
        for (int j=0;j<n;j++)
            printf("%d",s1[j]);

    }
    return 0;
}