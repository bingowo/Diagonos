#include <stdio.h>

int main()

{

    char table[21]="0123456789ABCDEFGHIJ";

    int num,r;

    while (scanf("%d%d",&num,&r)!=EOF)

    {

        printf("%d=",num);

        int digit[32]={0},cnt=0;

        do {

           int t=num%r;

           num=num/r;

           if (t<0) {t=t-r; num++; }

           digit[cnt++]=t;

        } while (num!=0);

        int i;

        for (i=cnt-1;i>=0;i--)

          printf("%c",table[digit[i]]);

        printf("(base%d)\n",r);

    }

    return 0;

}