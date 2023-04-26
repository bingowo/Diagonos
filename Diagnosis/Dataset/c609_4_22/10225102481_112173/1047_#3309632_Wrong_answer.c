#include <stdio.h>
#include <stdlib.h>

#define N 95


typedef struct { int cnt,v[N]; } BIGINT ;

void int2BIG(int x)  //int 转换成BIGINT
{
    BIGINT R= {0,{0}};
    do
    {
        R.v[R.cnt++]=x%10;
        x/=10;
    } while (x>0);
     for(int j=N;j>=0;j--)printf("%d",R.v[j]);
}



int main()
{
    int n;
    scanf("%d",&n);
    int i;
    for(i=0;i<n;i++)
    {

        printf("case #%d\n:",i);
        int x;
        scanf("%d",&x);
        int2BIG(x);

    }
   return 0;
}
