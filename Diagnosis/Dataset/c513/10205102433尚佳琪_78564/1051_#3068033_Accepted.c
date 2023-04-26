#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#include<string.h>
int main()
{
    char base64_chart[] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/="};
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        char s[150];
        char res[1500];
        scanf("%s",s);
        int len=strlen(s);
        int bits=0,pos=0,le=0;
        for(int i=0;i<len;i++)
        {
            int ch=s[i];
            int cur=(le<<(6-bits))+(ch >> (2 + bits));
            res[pos++] = base64_chart[cur];
            bits+=2;
            le = ch % (1 << bits);//bit=2时%4，bit=4时%16
            if(bits == 6)
            {
                res[pos++] = base64_chart[le];
                bits = 0;
                le = 0;
            }
        }
        if(bits == 2) //最后一组只有1个字符
        {
            res[pos++] = base64_chart[le << 4];
            res[pos++] = '=';
            res[pos++] = '=';
        }
        else if(bits == 4) //最后一组只有2个字符
        {
            res[pos++] = base64_chart[le << 2];
            res[pos++] = '=';
        }
        res[pos] = '\0';
         printf("case #%d:\n",i);
            printf("%s\n",res);
    }

}
