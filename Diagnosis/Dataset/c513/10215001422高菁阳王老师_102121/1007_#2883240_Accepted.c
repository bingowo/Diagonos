#include <stdio.h>
#include <stdlib.h>

int ling (int a[])
{
    int i;

    for(i=31;i>=0;i--)
    {
        if(a[i]==1) break;
    }
   
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
       
        pl=ling(a);
        
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
        
        printf("case #%d:\n%d\n",i,m);

    }
    return 0;
}