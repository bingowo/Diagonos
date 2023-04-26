#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 1000

int main()
{
    char* a = (char*)malloc(501*sizeof(char));
    char* b = (char*)malloc(501*sizeof(char));
    char* c = (char*)malloc(501*sizeof(char));
    memset((char*)a, '0', 500*sizeof(char));
    memset((char*)b, '0', 500*sizeof(char));
    //memset((char*)c, '0', 500*sizeof(char));
    while(scanf("%s%s", a, b) != EOF)
    {
        int i, j, t;
        int flag = 1;
        for(i=0; i<501; i++)
        {
            if(a[i] > b[i])
                break;
            if(a[i] < b[i])
            {
                flag = -1;
                c = a;
                a = b;
                b = c;
                break;
            }
        }
        int lena = strlen(a);
        int lenb = strlen(b);

        for(i=lenb-1, t=lena-1; i>=0; i--, t--)
        {
            int carry = 0;
            carry = a[t] - b[i];
            if(carry<0)
            {
                a[t] = 10 + carry + '0';

                for(j=t-1; j>=0; j--)
                {
                    if(a[j]==0)
                    {
                        a[j] = '9';
                        continue;
                    }
                    else
                    {
                        a[j]--;
                        break;
                    }
                }
            }
            else
                a[t] = carry + '0';
        }
        if(flag == -1)
            printf("-");
        flag = 0;
        for(i=0; i<lena; i++)
        {
            if(a[i] != '0')
            {
                flag = i;
                break;
            }
        }
        for(t=flag; t<lena; t++)
            printf("%c", a[t]);
        printf("\n");
    }
    return 0;
}
