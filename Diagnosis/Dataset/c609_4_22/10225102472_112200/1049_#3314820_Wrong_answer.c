#include<stdio.h>

#define LEN 550

void clear(int a[]);

void read(int a[]);

void print(int a[]);

void sub(int a[], int b[], int c[]);

int main()
{
    int a[LEN], b[LEN], c[LEN];

    read(a);
    read(b);

    sub(a, b, c);

    print(c);

    return 0;
}

void clear(int a[])
{
    for(int i=0; i<LEN; i++)
    {
        a[i] = 0;
    }
}

void read(int a[])
{
    static char s[LEN+1];
    scanf("%s", s);

    clear(a);

    int len = strlen(s);

    for(int i=0; i<len; i++) //反转
    {
        a[len-i-1] = s[i] - '0';
    }
}

void print(int a[])
{
    int i = 0;
    for(i=LEN-1; i>0; i--) //不输出前导0
    {
        if(a[i]!=0) break;
    }

    for(; i>=0; i--)
    {
        putchar(a[i]+'0');
    }

    putchar('\n');
}

void sub(int a[], int b[], int c[])
{
    clear (c);

    for(int i=0; i<LEN-1; i++)
    {
        c[i] += a[i] - b[i];

        if(c[i] < 0)
        {
            c[i+1] -= 1;
            c[i] += 10;
        }
    }
}