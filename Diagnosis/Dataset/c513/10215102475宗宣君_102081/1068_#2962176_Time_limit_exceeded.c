#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    int n,m;
    while(1)
    {
        scanf("%d %d",&n,&m);
        if(n==-1&&m == -1) break;
        int A = pow(2,n)-1,res = 0,B = 0,i;
        for(i = 0;i<m;i++)
            B = B + pow(2,i);
        while(A>0)
        {
            for(i = 0;i<=n-m;i++)
            {
                if((A&(B<<i))==B<<i) {res++;break;}
            }
            A--;
        }
        printf("%d\n",res);


    }
    return 0;
}
