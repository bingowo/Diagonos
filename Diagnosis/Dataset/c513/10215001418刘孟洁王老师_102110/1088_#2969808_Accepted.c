#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int cas,n,i,j,k,len,tmp,d,m,m1,x;
    int C[1007],CC[1007];
    scanf("%d",&cas);
    for(i = 0; i < cas; i++)
    {
        for(j = 0; j < 1007; j++){C[j] = 1;CC[j] = 0;}
        scanf("%d%d",&m,&n);
        x = n < (m-n)?n:m-n;
        if(n == 0){printf("case #%d:\n1\n",i);continue;}
        C[0] = 1;
        len = 1;
        for(j = 0; j < x; j++)
        {
            for(k = 0; k < len; k++)C[k] *= (m-j);
            m1 = 0;
            for(k = 0; k < len; k++)
            {
                tmp = C[k] + m1;
                C[k] = tmp%10;
                m1 = tmp/10;
            }
            while(m1)
            {
                C[len] = m1%10;
                m1 /= 10;
                len++;
            }
            for(k = len-1; k >= 0; k--)
            {
                tmp = C[k] + m1;
                C[k] = tmp/(j+1);
                m1 = tmp%(j+1)*10;
            }
        }
        for(j = 0; j <= (len-1)/2; j++)
        {
            d = C[j];
            C[j] = C[len-1-j];
            C[len-1-j] = d;
        }
        int f = 1;
        for(j = 0,k = 0; j <len; j++)
        {
            if(f && C[j] == 0)continue;
            f = 0;
            CC[k] = C[j];
            k++;
        }
        printf("case #%d:\n",i);
        for(j = 0; j < k; j++)printf("%d",CC[j]);
        printf("\n");
    }
    return 0;
}