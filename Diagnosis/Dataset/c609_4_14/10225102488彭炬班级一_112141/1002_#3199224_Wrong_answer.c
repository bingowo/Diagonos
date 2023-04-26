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
        int x=1,a=1,y=0;
        for(y=0;y<j-1;y++)
        {
            if(b[y]!=b[y+1])
                a++;
            else if(b[y]==b[y+1])
            {
                a=1;
                continue;
            }
            if(a>x)
                x=a;
        }
        printf("case #%d：\n",i);
        printf("%d\n",x);
    }
    return 0;
}
