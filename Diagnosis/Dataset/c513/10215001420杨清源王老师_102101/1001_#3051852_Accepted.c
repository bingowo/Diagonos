#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int T;
    scanf("%d",&T);
    int cas=0;
    for(cas=0; cas<T; cas++)
    {
        int N,R,i=0,j=0,tmp;
        scanf("%d%d",&N,&R);
        if(N<0)
        {
            printf("-");
            N=-N;
        }
        int a[100];//用于存放余数
        while(N!=0)
        {
            tmp=N%R;
            if(tmp>=0&&tmp<=9)
                tmp+=48;
            if(tmp>=10&&tmp<=35)
                tmp+=55;
            a[i]=tmp;
            N=N/R;
            i++;
        }
        for(;j<i;j++)
            printf("%c",a[i-j-1]);
        printf("\n");
    }
}
