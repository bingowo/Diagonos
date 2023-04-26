#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n,i,j,k,len,tmp,d,m;
    int C[1007];
    scanf("%d",&n);
    for(i = 0; i < n; i++)
    {
        memset(C,1,sizeof(C));
        scanf("%d%d",&m,&n);
        C[0] = 1;
        len = 1;
        for(j = 0; j <= n; j++)
        {
            for(k = 0; k < len; k++)
            {
                C[k] *= (m-j);
                C[k] /= (j+1);
            }
            m = 0;
            for(k = 0; k < len; k++)
            {
                tmp = C[k] + m;
                C[k] = tmp%10;
                m = tmp/10;
            }
            while(m)
            {
                C[len] = m%10;
                m /= 10;
                len++;
            }
        }
        for(j = 0; j < (len-1)/2; j++)
        {
            d = C[j];
            C[j] = C[len-1-j];
            C[len-1-j] = d;
        }
        printf("case #%d:\n",i);
        for(j = 0; j < len; j++)printf("%d",C[j]);
        printf("\n");
    }
    return 0;
}