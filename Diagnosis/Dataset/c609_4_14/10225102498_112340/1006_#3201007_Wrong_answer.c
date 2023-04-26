#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    int T,i;
    char s[65];
    char s1[65];
    char c;
    scanf("%d",&T);
    for(i=0; i<T; i++)
    {
        int j = 0, B = 0, k = 0;
        while((c=getchar())!='\n')
        {
            s[j] = c;
            for(int t=0; t<=j; t++)
            {
                if(t==j)
                {
                    s1[k] = s[j];
                    B++;
                }
                if(s[j]==s[t])
                    break;
            }
            j++;
        }
        int len = strlen(s1);
        for(int t=0; t<len; t++)
        {
            for(k=0; k<j; k++)
            {
                if(s[k] == s1[t])
                {
                    if(t<10)
                        s[k] = t + '0';
                    if(t>=10)
                        s[k] = t - 10 + 'A';
                }
            }
        }
        int n = 0, b = 1;
        for(k=j; k>=0; k--)
        {
            if(s[k]<='9')
                n += (s[k] - '0')*b;
            else
                n += (s[k] - 'A' + 10)*b;
            b *= B;
        }

        printf("case#%d:\n%d\n" ,i, n);
    }

    return 0;
}
