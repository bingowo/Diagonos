#include <stdio.h>
#include <stdlib.h>

int main()
{
    char d[37] = {"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    int i = 0;
    int num,base;
    int arr[10000];
    scanf("%d%d",&num,&base);
    while(num)
        {
            int temp = num % base;
            num /= base;
            if(temp < 0)
            {
                temp -= base;
                num++;
            }
            arr[i++] = temp;
        }
        for(int j = 0,c = i-1; j < c;j++,c--)
        {
            int x = arr[c];
            arr[c] = arr[j];
            arr[j] = x;
        }

        for(int j = 0;j < i;j++)
        {
            printf("%c",d[arr[j]]);
        }
}
