#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char change(int n)
{
    if (n>=0&&n<=25) return 'A'+n;
    if (n>=26&&n<=51) return 'a'+n-26;
    if (n>=52&&n<=61) return '0'+n-52;
    if (n==62) return '+';
    else return '/';
}
int main()
{
    int T;
    scanf ("%d",&T);
    getchar();
    for (int q=0;q<T;q++)
    {
        char s[101]={};
        int two[801]={},ten[801]={};
        scanf("%s",s);
        int len=strlen(s);
        for (int i=0;i<len;i++)
        {
            int t;
            t=s[i];
            for (int j=7;j>=0;j--)
            {
                two[i*8+j]=t%2;
                t=t/2;
            }
        }
        int len2=len*8;
        while (len2%6!=0)
        {
            two[len2]=0;
            len2++;
        }//补齐
        for (int i=0;i<len2;i+=6)
        {
            ten[i/6]=0;
            for (int j=0;j<6;j++)
            {
                ten[i/6]=ten[i/6]*2+two[i+j];
            }
        }//十进制
        int len3=len2/6;
        printf("case #%d:\n",q);
        for (int i=0;i<len3;i++)
        {
            printf("%c",change(ten[i]));
        }
        if (len3%4)
        {
            for (int i=len3%4;i<4;i++)
                printf("=");
        }
        printf("\n");

    }
    return 0;
}
