#include <stdio.h>
#include <stdlib.h>

int main()
{
    typedef struct
    {
        int cnt;
        int bigint[100];
    }BIGINT;
    short T=0;
    scanf("%hd",&T);
    for(int i=0;i<T;i++)
    {
        short base=0,n=0;
        BIGINT N;
        scanf("%hd%hd",&base,&n);
        N.cnt=1;
        N.bigint[0]=1;
        for(int j=0;j<n;j++)
        {
            int carry=0;
            for(int k=0;k<N.cnt;k++)
            {
                N.bigint[k]=N.bigint[k]*base+carry;
                carry=N.bigint[k]/10;
                N.bigint[k]%=10;
            }
            if(carry)
            {
                N.bigint[N.cnt]=carry;
                N.cnt++;
            }
        }
        printf("case #%d:\n",i);
        for(int j=N.cnt-1;j>=0;j--)
            printf("%d\n",N.bigint[j]);
    }
    return 0;
}
