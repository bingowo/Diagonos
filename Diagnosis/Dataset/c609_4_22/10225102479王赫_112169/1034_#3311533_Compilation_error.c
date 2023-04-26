#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char* s=(char*)malloc(sizeof(char)*100000);
    scanf("%s",s);
    int i=0;
    int n=0;
    (unsigned int)* sum=(unsigned int*)malloc(ssizeof(unsigned int)*100000);
    while(s[i]!='0')
    {
        i++;
        if(s[i]=='x')
        {
            char c=(char*)malloc(sizeof(char)*100000)
            c[0]='0';
            c[1]='x';
            for(int j=2;s[j]!='x';j++)
            {
                strcpy(c,s[j]);
            }
            c[j-1]='0';
            int len=strlen(c);
            for(int j=0;j<len;j++)
            {
                if(c[j]-'0'>=0&&c[j]-'0'<=9) sum[n]+=sum*16+c[j]-'0';
                else sum[n]+=sum[n]*16+c[j]-'87';
            }
            n++;
        }
    }
    int k=0;
    while(sum[k])
    {
        k++;
    }
    int cnt=k;
    if(sum[0])
    {
        for(int k=0;k<cnt;k++) printf("%u ",sum[k]);
    }
    printf("-1");
    return 0;
}
