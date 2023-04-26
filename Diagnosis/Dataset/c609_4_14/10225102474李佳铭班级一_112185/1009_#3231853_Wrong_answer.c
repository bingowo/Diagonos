#include <stdio.h>
#include <stdlib.h>
#include<string.h>

/*int count(char*s)
{
    int a = 0;
    for(int i = 0;i < strlen(s);i++)
    {
        int b = 1;
        for(int j = 0; j < 8; j++)
        {
            if(s[i] & b)
            {
                a++;
            }

            b = b << 1;
        }

    }
    return a;
}*/
void gcd(int a,int b)
{
    int a1 = a;
    int b1 = b;
    while(a % b)
    {
        int temp = a % b;
        a = b;
        b = temp;
    }
    a1 /= b;
    b1 /= b;
    printf("%d/%d\n",b1,a1);
}


int main()
{
    int T = 0;
    int len = 0;
    int pc = 0;
    scanf("%d",&T);
    getchar();
    for(int i = 0; i < T;i++)
    {
        char str[1000];
        char c;
        int j = 0;
        while((c = getchar()) != '\n')
        {
            str[j++] = c;
        }
        str[j] = '\0';

        int a = 0;

    for(int e = 0;e < strlen(str);e++)
    {
        int b = 1;
        for(int x = 0; x < 8; x++)
        {
            if(str[e] & b)
            {
                a++;
            }

            b = b << 1;
        }

    }

        len += j;

      //  pc = count(str) / (8 * len);
        gcd(8*len,a);


    }
    return 0;
}
