#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int T,i;
    char table[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz+/";
    scanf("%d",&T);
    for(i = 0;i < T;i++)
    {
        char input[101];
        scanf("%s",input);
        int code = 0,count = 0,j,k;
        int len = strlen(input),wei =len*8 + 6 - (len*8)%6;
        //wei为分配的二进制位
        int*binary,byte = len*8 - 1;
        binary = (int*)malloc(sizeof(int)*wei);
        memset(binary,0,sizeof(int)*wei);
        for(j = len - 1;j >= 0;j--)
        {
            for(k = 0;k < 8;k++)
            {
                binary[byte--] = (input[j]>>k)&1;
            }
        }
        printf("case #%d:\n",i);
        for(j = 0;j < wei;j += 6)
        {
            for(k = 0;k < 6;k++)
                code = code*2 + binary[j + k];
            printf("%c",table[code]);
            count++;
            code = 0; 
        }
        if(count%4 != 0)
        {
            for(j = 0;j < count%4;j++)
                printf("=");
        }
        free(binary);
        putchar('\n');
    }
}