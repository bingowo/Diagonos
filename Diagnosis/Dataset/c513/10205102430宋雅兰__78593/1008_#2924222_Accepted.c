#include<stdio.h>
int main()
{
    int T,x,y,t;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        scanf("%d%d",&x,&y);
        t=x^y;
        int count=0;
        while(t){
            count+=t%2;
            t=t>>1;
        }
        printf("%d\n",count);
    }
    return 0;
}