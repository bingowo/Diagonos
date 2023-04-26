#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{

    int T;
    scanf("%d",&T);
    getchar();
    for(int i=0;i<T;i++)
    {
        long long int n,ans=0,c;
        int a[100],b[100],h=0;
        scanf("%lld",&n);
        int j=0;
        while(n)
        {
            a[j]=n%2;
            n=n/2;
            j+=1;
        }

        for(int m=0;m<j;m++)
        {
           if(a[m]!=a[m+1])ans=ans+1;
           else
           {
               b[h++]=ans+1;
               ans=0;
           }
        }
        c=b[0];
        for(int x=1;x<h;x++)
        {
            if(ans<b[x])c=b[x];
        }
        for(int m=0;m<j;m++)
        {
            if(a[m]==a[m+1])break;
            else c=j;
        }
        printf("case #%d:\n%lld\n",i,c);
    }
    return 0;
}
