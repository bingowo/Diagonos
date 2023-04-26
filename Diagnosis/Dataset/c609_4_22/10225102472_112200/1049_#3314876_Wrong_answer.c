#include<stdio.h>

#define LEN 550

void clear(int a[]);

void read(int a[]);

void print(int a[]);

void sub(int a[], int b[], int c[]);

int main()
{
    int a[LEN]={0}, b[LEN]={0}, c[LEN]={0};
    char ss[LEN];
    char ch;

    do
    {
        read(a);
        read(b);

        int k, flag=1;

        for(k=LEN-1; k>=0; k--)
        //sub 函数只能处理 a>b 的情况
        {
            if(a[k] > b[k]) break;
            if(a[k] < b[k])
            {
                flag = -1;
                break;
            }
        }

        if(flag == 1)
        {
            sub(a, b, c);
            print(c);
        }

        else
        {
            sub(b, a, c);
            putchar('-');
            print(c);
        }
    }while((ch=getchar()) == '\n' ? 1 : 0);

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