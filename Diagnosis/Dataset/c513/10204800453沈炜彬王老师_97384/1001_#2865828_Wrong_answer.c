#include <stdio.h>
#include <stdlib.h>

int
main()
{
    char c[36]={"0123456789ABCDeFGHIJKLMNOPQRSTUVWXYZ"};
    char result[1000] = {0};
    int questions;

    scanf("%d",&questions);

    for (int i=0;i<questions;i++)
    {
        int N,R;
        int count=0;
        int judge = 1;

        scanf("%d%d",&N,&R);
        if (N<0) judge=-1,N*=(-1);
        while(N!=0)
        {
            *(result+count) = *(c+N%R);
            count++;
            N /= R;
        }
        if (judge==-1) printf("-");
        for (int i=count-1;i>-1;i--)
        {
            printf("%c",*(result+i));
            if (i==0) printf("\n");
        }
    }
    
    return 0;
}