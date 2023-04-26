#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int t;
    scanf("%d",&t);
    char base64_chart[] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/="};
    for(int i=0;i<t;i++)
    {
        char s[200];
        scanf("%s",s);
        int len=strlen(s);
        printf("case #%d:\n",i);
        if(len%3==0)
        {
            for(int i=0;i<len;i+=3)
            {
                long long int num=s[i]*65536+s[i+1]*256+s[i+2];
                long long int x1=num>>18,x2=(num>>12)-((num>>18)<<6),x3=(num>>6)-((num>>12)<<6),x4=num-((num>>6)<<6);
                printf("%c%c%c%c",base64_chart[x1],base64_chart[x2],base64_chart[x3],base64_chart[x4]);
            }
        }
        else if(len%3==2)
        {
            for(int i=0;i<len-2;i+=3)
            {
                long long int num=s[i]*65536+s[i+1]*256+s[i+2];
                long long int x1=num>>18,x2=(num>>12)-((num>>18)<<6),x3=(num>>6)-((num>>12)<<6),x4=num-((num>>6)<<6);
                printf("%c%c%c%c",base64_chart[x1],base64_chart[x2],base64_chart[x3],base64_chart[x4]);
            }
            long long int num=s[len-2]*256+s[len-1];
            num=num<<2;
            long long int x1=num>>12,x2=(num>>6)-((num>>12)<<6),x3=num-((num>>6)<<6);
            printf("%c%c%c=",base64_chart[x1],base64_chart[x2],base64_chart[x3]);
        }
        else if(len%3==1)
        {
            for(int i=0;i<len-1;i+=3)
            {
                long long int num=s[i]*65536+s[i+1]*256+s[i+2];
                long long int x1=num>>18,x2=(num>>12)-((num>>18)<<6),x3=(num>>6)-((num>>12)<<6),x4=num-((num>>6)<<6);
                printf("%c%c%c%c",base64_chart[x1],base64_chart[x2],base64_chart[x3],base64_chart[x4]);
            }
            long long int num=s[len-1];
            num=num<<4;
            long long int x1=num>>6,x2=num-((num>>6)<<6);
            printf("%c%c==",base64_chart[x1],base64_chart[x2]);
        }
        printf("\n");
    }
    return 0;
}
