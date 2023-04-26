#include <stdio.h>
#include <stdlib.h>

int ling (int a[])
{
    int i;

    for(i=31;i>=0;i--)
    {
        if(a[i]==1) break;
    }
    //printf("i=%d\n",i);
    return i+1;
}

int main()
{
    int t,i;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        int n,j,a[50],k,co=1,m=1,pl;
        scanf("%d",&n);
        for(j=0;j<32;j++)
        {
            a[j]=n%2;
            n=n>>1;
        }
       /* for(int u=0;u<32;u++)
    {
        printf("u[%d]=%d\n",u,a[u]);
    }*/
        pl=ling(a);
        //printf("test: pl=%d\n",pl);
        for(k=0;k<pl;k++)
        {
            if(a[k]==a[k+1]) continue;
            else
            {

                for(j=k,co=1;j<pl-1;j++)
                {
                    if (a[j]!=a[j+1]) co++;
                    else
                    {

                        break;
                    }

                }
                if(co>m) m=co;
            }
        }
        //printf("test: m=%d co=%d\n",m,co);
        printf("case #%d:\n%d\n",i,m);

    }
    return 0;
}
