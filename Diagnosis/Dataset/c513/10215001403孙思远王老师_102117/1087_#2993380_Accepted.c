#include <stdio.h>
#include <stdlib.h>


int main()
{
    int t,T;
    scanf("%d\n",&T);
    for(t=0;t<T;t++)
    {
        printf("case #%d:\n",t);
        int s[102]={0},s2[102]={0},i=1,n,N,x,w,flag;
        char c;
        while(1)
        {
            scanf("%c",&c);
            if(c!='\n')
            {
                s[i]=c-'0';
                i++;
            }
            else
                break;
        }
        n=i-1;
        s[n]++;
        for(i=n;i>0;i--)
        {
            if(s[i]>9)
            {
                s[i-1]++;
                s[i]%=10;
            }
        }
        for(i=0;i<=n;i++)
            s2[i]=s[i];
        w=n;
        do
        {
            flag=0;
            x=s[0];
            for(i=1;i<=w;i++)
            {
               if(s[i]==x)
               {
                   s[i]++;
                   w=i;
                   flag=1;
                   break;
               }
               x=s[i];
            }
            for(i=n;i>0;i--)
            {
               if(s[i]>9)
               {
                   s[i-1]++;
                   s[i]%=10;
               }
            }
        }while(w>0&&flag==1);
        for(i=0;i<=n;i++)
        {
            if(s[i]!=s2[i])
            {
                i++;
                break;
            }
        }
        for(;i<=n;i++)
        {
            s[i]=0;
            if(i+1<=n)
            {
                i++;
                s[i]=1;
            }
        }
        if(s[0]!=0)
            printf("%d",s[0]);
        for(i=1;i<=n;i++)
            printf("%d",s[i]);
        printf("\n");
    }
    return 0;
}
