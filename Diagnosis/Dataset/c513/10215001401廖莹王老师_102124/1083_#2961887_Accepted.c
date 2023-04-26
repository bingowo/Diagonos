#include <stdio.h>
#include <stdlib.h>

void jisuan(int h)
{
    int n;
    scanf("%d",&n);
    int i=0,count=0,j=0,k=5;
    for(i=n;i>=5;i--)
    {    k=5;
        for(j=0;;j++)
        {
            if(i%k==0){count++;k=k*5;}
            else break;
        }
    }
    printf("case #%d:\n",h);
    printf("%d\n",count);
}
int main()
{
    int N,h;
    scanf("%d",&N);
    for(h=0;h<N;h++)jisuan(h);
}
