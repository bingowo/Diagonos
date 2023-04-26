#include <stdio.h>
#include <stdlib.h>
int max(int a,int b)
{
    if (a>b)
    {
        return a;
    }
    if (b>a)
    {
        return b;
    }
}
int min(int a,int b)
{
    if (a<b)
    {
        return a;

    }
    if (b<a)
    {
        return b;
    }
}




int main()
{
    int T;
    scanf("%d",&T);
    for(int cas=0;cas<T;cas++)
    {
        int N;
        scanf("%d",&N);
        int i=0;
        int a[100];
        while (i<N)
        {
            int p;

            scanf("%d",&p);
            i+=1;
            if (p==0)
            {
                a[0]=65;
                continue;
            }

            int j=0;
            int k=0;
            while (j<64)
            {
                int mask=1LL<<j;
                j+=1;
                if (mask&p==1)
                {
                    k+=1;
                }

            }
            if (a[k]==0)
                {
                    a[k]=p;
                }
            else if (a[k]!=0)
            {
              a[k]=min(a[k],p);
              a[k+1]=max(a[k],p);
            }

        }
        int m=sizeof(a)/sizeof(int);
        int w=0;
        for (;w<m;)
        {  int y;
            if (a[w]==0)
            {
                y=w;
                for (;y<m;)
                {
                    a[y]=a[y+1];
                    y+=1;
                }
                m-=1;
                y-=1;
            }
            w+=1;
        }
        if (a[0]==65)
        {
            a[0]=0;
        }
        int u=sizeof(a)/sizeof(int)-1;
        printf ("case #%d:\n",cas);
        while (u!=0)
        {
            printf ("%d",a[u]);
            printf (' ');
            u-=1;
        }
        printf ("%d",a[u]);
    }
    return 0;
}
