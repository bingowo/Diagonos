#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m,x,y;
    int count;
    scanf("%d",&m);
    for(int s=0;s<m;s++)
    {
        count=0;
        scanf("%d %d",&x,&y);
        int x1[32]={0},y1[32]={0};
        ao(x,x1);
        ao(y,y1);
        for(int t=0;t<32;t++)
        {
            if(*(x1+t)!=*(y1+t)) count++;
        }
        printf("%d\n",count);
    }
    return 0;
}
void ao(int n,int *a)
{
    int i=0;
    while(n!=0)
    {
        *(a+i)=n%2;
        n=n/2;
        i++;
    }
}
