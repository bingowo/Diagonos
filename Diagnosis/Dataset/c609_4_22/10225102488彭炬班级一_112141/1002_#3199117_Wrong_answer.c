#include <stdio.h>

int main()
{
    int T;scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        int n,b[32],j;
        scanf("%d",&n);
        for(j=0;n>0;j++)
        {
            b[j]=n%2;
            n/=2;
        }
        int x=1,a=0,y=0;
        for(y=0;y<j;y++)
        {
            if(b[y]!=b[y+1])
                a++;
                if(a>x)
                    x=a;
            else if(b[y]==b[y+1])
            {
                a=0;
                continue;
            }
        }
        if(b[j-1]==b[j-2])
            x++;
        printf("case #%d\n",i);
        printf("%d\n",x);
    }
    return 0;
}
