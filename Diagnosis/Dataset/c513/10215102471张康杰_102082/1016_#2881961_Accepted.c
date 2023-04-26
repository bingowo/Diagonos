#include <stdio.h>
#include <stdlib.h>
int main()
{
    int N,R;
    scanf("%d %d",&N,&R);
    char table[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char output[20];
    int remainder,i = 0,j;
    do
    {
        remainder = N%R;
        N = N/R;
        if(remainder < 0)
        {
            remainder -= R;
            N += 1;
        }
        output[i] = table[abs(remainder)];
        i++;
    }while(N != 0);
    for(j = i - 1;j > -1;j--)
        printf("%c",output[j]);
    //putchar('\n');
    return 0;
}
