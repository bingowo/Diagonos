#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char ss[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};

int main()
{
    char s[120]={0};
    int A,B;
    unsigned long long c=0;
    scanf("%d %s %d",&A,s,&B);
    for (int i=0;i<strlen(s);i++)
    {
        if (isdigit(s[i]))
            c=c*A+(s[i]-'0');
        else
        {
            c=c*A+(toupper(s[i])-'A'+10);
        }
    }
    char ret[120]={0};
    int j=0;
    while (c)
    {
        ret[j++]=ss[c%B];
        c=c/B;
    }
    for (j=0;j<strlen(s)&& s[j]=='0';j++);
    if (j==strlen(s))
        printf("0");
    else
    {
        for (int i=strlen(ret)-1;i>=0;i--)
        printf("%c",ret[i]);
    }
    printf("\n");
    return 0;
}
