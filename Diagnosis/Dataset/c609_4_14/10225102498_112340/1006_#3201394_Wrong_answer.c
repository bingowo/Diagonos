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
        int B = 0, k = 0, t = 0;
        int j;
        scanf("%s",s);
        int p = strlen(s);
        for(j=0; j<p; j++)
        {
            for(t=0; t<=j; t++)
            {
                if(t==j)
                {
                    s1[k] = s[j];
                    //printf("s1[%d]=%c\n",k,s1[k]);
                    B++;
                    k++;
                }
                if(s[t]==s[j])
                    break;
            }

        }
        //printf("B=%d\ns1=%s\ns=%s\n",B,s1,s);
        int len = strlen(s1);
        //printf("len=%d\n",len);
        for(t=0; t<len; t++)
        {
            for(k=0; k<p; k++)
            {
                if(s[k]==s1[t])
                {
                    if(t<10&&t>1)
                        s[k] = t + '0';
                    if(t>=10)
                        s[k] = t - 10 + 'A';
                    if(t==0)
                        s[k] = '1';
                    if(t==1)
                        s[k] = '0';
                }
            }
        }
        //printf("s=%s\n",s);
        long long n = 0, b = 1;
        for(k=p-1; k>=0; k--)
        {
            if(s[k]<='9')
                n += (s[k] - '0')*b;
            if(s[k]>='A')
                n += (s[k] - 'A' + 10)*b;
            b *= B;
        }

        printf("case #%d:\n%lld\n" ,i, n);
    }

    return 0;
}
