#include <stdio.h>
#include <stdlib.h>
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
        int lena = strlen(a);
        int lenb = strlen(b);
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

        for(i=lenb, t=lena; i>=0; i--, t--)
        {
            int carry = 0;
            carry = a[t] - b[i];
            if(carry<0)
            {
                a[t] = 10 + carry;

                for(j=t-1; j>=0; j--)
                {
                    if(a[j]==0)
                    {
                        a[j] = 9;
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
                a[t] = carry;
        }


    }
    return 0;
}
