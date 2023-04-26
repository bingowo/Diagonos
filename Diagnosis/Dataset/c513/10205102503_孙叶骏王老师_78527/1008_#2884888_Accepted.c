#include <stdio.h>

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        int z=x^y;
        int count=0;
        while(z)
        {
            if(z%2==1)count++;
            z/=2;
        }
        printf("%d\n",count);
    }
}