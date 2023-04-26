#include<stdio.h>
#include<stdlib.h>
int main()
{
    long long int a,b,c,d,l;
    scanf("%lld %lld",&a,&b);
    c=a/b;
    d=a%b;
    l=d;
    int s[10000];
    int i=0,dot,r=0,w=b;
    w=w/3;
    while(w)
    {
        r+=1;
        w=w/3;
    }
    if(d!=0)
    {

        while(d)
            {
                s[i]=d%3;
                d=d/3;
                i=i+1;
            }
            while(i<r)
            {
                s[i]=0;
                i=i+1;
            }
    }
    dot=i;
    if(c!=0)
    {
        while(c)
        {
            s[i]=c%3;
            c=c/3;
            i+=1;
        }
    }
    else
        {
            s[i]=0;
    i+=1;
    }
    s[i]=0;
    for(int j=0;j<i;j++)
    {
        s[j]=s[j]+1;
        if(s[j]==3)
        {
            s[j]=0;
            s[j+1]+=1;
        }
        if(s[j]==4)
        {
            s[j]=1;
            s[j+1]+=1;
        }
        s[j]-=1;
        if(s[j]==-1)s[j]=2;
    }
    for(int j=i;j>=dot;j--)
    {
        if(j==i&&s[j]==0)continue;
        printf("%d",s[j]);
    }
    if(l!=0)
    {
        int j=0;
        for(;j<dot-1;j++)
        {
           if(s[j]!=0)break;
        }
        if(j!=(dot))
        {
            printf(".");
            for(int k=dot-1;k>=j;k--)
            {
                printf("%d",s[k]);
            }

        }


    }
    return 0;
}
