#include <stdio.h>
int main()
{
    int i,j,T,x[100],y[100],m,n;
    scanf("%d",&T);
    for(i = 0;i<T;i++)
        scanf("%d %d",&x[i],&y[i]);
    for(i = 0;i<T;i++)
    {   n =0;
        m = x[i]^y[i];
        for(j =0;j<32;j++)
            if(m&1<<j) n++;
        printf("%d\n",n);
    }
    return 0;
}
