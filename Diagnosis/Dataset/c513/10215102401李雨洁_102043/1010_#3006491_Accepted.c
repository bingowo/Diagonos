#include <stdio.h>
#include <string.h>

void trans2(int len,int last)
{
    for(int i = 0; i < last * 3 + 1;i++)
    {
        int end = ( (len & (1 << last * 3)) ? 1 : 0);
        printf("%d",end);
        len <<= 1;
    }
}

int main()
{
    char a[2000] = {0};
    scanf("%s",a);
    printf("0001");
    int len = strlen(a);
    int num[10];
    trans2(len,3);
    int times = len / 3;
    int last;
    if(times * 3 < len)
    {
        last = len - times * 3;
        times++;
    }
    else
        last = 3;
    for(int i = 0; i < times; i++)
    {
        int t = 0;
        for(int j = 0; j < 3; j++)
        {
            if(a[3 * i + j] == '\0') break;
            t *= 10;
            t += (a[3 * i + j] - '0');
        }
        (i != times - 1) ? trans2(t,3) : trans2(t,last);
    }
}

