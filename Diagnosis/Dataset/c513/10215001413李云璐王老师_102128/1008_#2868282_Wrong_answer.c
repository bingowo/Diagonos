#include<stdio.h>
int main()
{
    int T;
    scanf("%d\n",&T);
    for(int i=0;i<T;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        int count=0;
        for(int k=0;k<32;k++)
        {
            if((x>>k)&1==(y>>k)&1)
            count++;
        }
        printf("%d\n",count);
    }
    return 0;
}