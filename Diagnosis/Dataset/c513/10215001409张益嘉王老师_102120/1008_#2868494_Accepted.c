#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t,i;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        int j,c=0;
        int x,y,m;
        scanf("%d%d",&x,&y);
        m=x^y;

        for(j=0;j<32;j++)
        {
            if((m&1)==1) c++;
            m=m>>1;

        }
        printf("%d\n",c);

    }
    return 0;

}
