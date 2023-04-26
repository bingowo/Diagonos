#include<stdio.h>
#include<stdlib.h>
char table[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int main()
{
    int num, base;
    scanf("%d %d", &num, &base);

    int s, r;
    int k = 0;
    int n[50] = {0};
    int ans = 0;

    if(num == 0) printf("0");
    while(num)
    {
        r = num % base;
        num = num / base;
        if(r < 0)
        {
            r -= base;
            num += 1;
        }
        n[k++] = table[r];
    }
    for(int i = k - 1; i >= 0; i--)
        printf("%c", n[i]);
    return 0;
}


