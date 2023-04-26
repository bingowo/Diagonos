#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int main()
{
    char s;
    int c = 0, t = 0;
    int z1[550] = { 0 }, f1[550] = { 0 };
    int z2[550] = { 0 }, f2[550] = { 0 };
    int resz[550] = { 0 }, resf[550] = { 0 };
    int lz1 = 0, lf1 = 0, lz2 = 0, lf2 = 0;
    int lf = 0, lz = 0;
    int n;
    int i = 0, j = 0, k = 0;
    int a = 0, b = 0,f=0;
    while ((s = getchar()) != '\n')
    {
        if (s == ' ')
        {
            b++;
            a = 0;
        }
        else if (s == '.')
        {
            a = 1;
        }
        if (b == 0)
        {
            if (a == 0)
            {
                z1[lz1] = s - '0';
                lz1++;
            }
            else if (a == 1)
            {
                f1[lf1] = s - '0';
                lf1++;
            }
        }
        else if (b == 1)
        {
            if (a == 0)
            {
                z2[lz2] = s - '0';
                lz2++;
            }
            else if (a == 1)
            {
                f2[lf2] = s - '0';
                lf2++;
            }
        }
        if (b == 2)
        {
            scanf("%d", &n);
            break;
        }
    }
    if (lf1 > lf2)
        lf = lf1;
    else
        lf = lf2;
    if (lz1 > lz2)
        lz = lz1;
    else
        lz = lz2;
    for (i = lf - 1; i >= 0; i--)
    {
        t = f1[i] + f2[i] + c;
        c = t / 10;
        resf[lf - 1 - i] = t % 10;
    }
    for (i = lz - 1; i >= 0; i--)
    {
        if ((lz1 < 1)&&(lz2>=1))
            t = z2[lz2 - 1] + c;
        else if ((lz2 < 1)&&(lz1>=1))
            t = z1[lz1 - 1] + c;
        else if((lz1>=1)&&(lz2>=1))
            t = z1[lz1-1] + z2[lz2-1] + c;
        c = t / 10;
        resz[lz - 1 - i] = t % 10;
        lz1--;
        lz2--;
    }
    if (c != 0)
    {
        resz[lz] = c;
        lz++;
        c = 0;
    }
    if (lf > n)
    {
        if (resf[lf - n - 1] > 4)
        {
            c = 1;
            for (i = lf - n; i < lf; i++)
            {
                resf[i] = resf[i] + c;
                c = resf[i] / 10;
                resf[i] = resf[i] % 10;
                if (c == 0)
                    break;
            }
            if (c != 0)
            {
                for (i = 0; i < lz; i++)
                {
                    resz[i] = resz[i] + c;
                    c = resz[i] / 10;
                    resz[i] = resz[i] % 10;
                }
                if (c != 0)
                {
                    resz[lz] = c;
                    lz++;
                    c = 0;
                }
            }
        }
    }
    if (lz == 0)
        printf("0.");
    else
    {
        for (i = lz - 1; i >= 0; i--)
        {
            if(lz==1)
                printf("%d",resz[i]);
            else
            {
                if(resz[i]!=0)
                {
                    printf("%d", resz[i]);
                    f=1;
                }
                else
                {
                    if(f!=0)
                    {
                        printf("%d", resz[i]);
                    }
                }
            }
        }
        printf(".");
    }
    i = lf - 1;
    for (j = 0; j < n; j++)
    {
        if (i < 0)
            printf("0");
        else
            printf("%d", resf[i]);
        i--;
    }
    printf("\n");
    return 0;
}