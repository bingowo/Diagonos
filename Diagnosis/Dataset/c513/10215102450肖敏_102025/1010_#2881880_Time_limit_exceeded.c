#include <stdio.h>

int main()
{
    int i,j,k,e =0,g;
    char s[500];
    int t[200],a[3500];
    scanf("%s",s);
    for(j = 0;j <200;j ++)
        t[j] = 0;
    for(i = 0,j = 0;s[i] != '\0';i ++)
    {
        t[j] = t[j] * 10 + s[i] - '0';
        if((i + 1) %3 == 0)
            j ++;
    }
    if((i % 3) == 0)
        g = 10;
    else
        g = 3 * (i % 3) + 1;
    for(k = 10;g > 0;k ++,g --)
    {
        a[k] = t[j] % 2;
        t[j] /= 2;
    }
    if(i > 3)
    {
        for(j -= 1;j >=0;j --)
        {
            for(g = 10;g > 0;g --)
            {
                a[k ++] = t[j] % 2;
                t[j] /= 2;
            }
        }
    }

    while(e < 10)
    {
        a[e++] = i % 2;
        i /= 2;
    }
    printf("0001");
    for(e=9;e >= 0;e--)
        printf("%d",a[e]);
    while(k > 10)
        printf("%d",a[k]);
    return 0;
}
