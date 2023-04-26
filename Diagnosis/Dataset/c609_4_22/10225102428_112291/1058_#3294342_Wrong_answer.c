#include <stdio.h>

int main()

{

    int num;

    while (scanf("%d",&num)!=EOF)

    {

        int digit[32]={0},cnt=0;

        do {

           int t=num%(-2);

           num=num/(-2);

           if (t<0) {t=t+2; num++; }

           digit[cnt++]=t;

        } while (num!=0);

        int i;

        for (i=cnt-1;i>=0;i--)

          printf("%d",digit[i]);


    }

    return 0;

}