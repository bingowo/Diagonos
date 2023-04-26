#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0; i<T; i++)
    {
        int n,s[50],j=0,count=1,z=0,comp[50];
        scanf("%d",&n);
        while(n>0)
        {
            s[j++]=n%2;
            n/=2;
        }
        while(j>1)
        {
            if(s[j-1]!=s[j-2])
                count++;
            else
            {
                comp[z++]=count;
                count=1;
            }
            if(j==2&&count!=1)
                comp[z]=count;
            else if(j==2&&count==1)
                z--;
            j--;
        }
        for(z; z>=0; z--)
        {
            if(comp[z]>count)
                count=comp[z];
        }
        printf("case #%d:\n%d\n",i,count);
    }
    return 0;
}
