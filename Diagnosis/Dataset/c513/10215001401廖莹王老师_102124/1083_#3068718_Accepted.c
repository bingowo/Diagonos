#include <stdio.h>
#include <stdlib.h>

void jisuan(int h)
{
     int n,i,k=0,j;
    scanf("%d",&n);
    for(i=5;i<=n;i++)
    {   int l=i;
        for(j=0;l>=5;j++){if(l%5==0){l=l/5;k++;}else break;}
    }
    printf("case #%d:\n",h);    
    printf("%d\n",k);
}
int main()
{
    int N,h;
    scanf("%d",&N);
    for(h=0;h<N;h++)jisuan(h);
}
