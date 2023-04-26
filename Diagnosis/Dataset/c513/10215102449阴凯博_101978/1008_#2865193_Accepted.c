#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T;
    scanf("%d",&T);
    for (int i=0;i<T;i++)
    {
        int x,y,j;
        scanf("%d %d",&x,&y);
        int m,n=0;
        m=x^y;
        for (j=0;m/2>0 || m==1;j++)
        {
            if (m%2) n++;
            m=m/2;
        }
        printf("%d\n",n);

    }
    return 0;
}
