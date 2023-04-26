#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 100200


typedef struct
{
    int o;
    char hex[100];
    unsigned int r;
}  NUMBER;

unsigned int htoi(char* s)
{
    unsigned int n=0;
    int i;
    for (i=0;i<strlen(s);i++)
    {
        if (isdigit(s[i]))
            n=n*16+s[i]-'0';
        if (isalpha(s[i]))
            n=n*16+s[i]-'a'+10;
    }
    return n;
}

int main()
{
    char s[MAX]={0};
    int i,n=0,j=0,m=0;
    scanf("%s",s);
    for (i=0;i<strlen(s)-1;i++)
    {
        if (s[i]=='0' && s[i+1]=='x')
            n++;
    }
    if (n==0)
        printf("-1\n");
    else
    {
        NUMBER* arr=(NUMBER*)malloc(n*sizeof(NUMBER));
        for (i=0;i<strlen(s)-1;i++)
        {
            if (s[i]=='0' && s[i+1]=='x')
                arr[j++].o=i;
        }
        for (i=0;i<n-1;i++)
        {
            for (m=0,j=arr[i].o+2;m<arr[i+1].o-2;m++,j++)
            {
                if (s[j]>'f')
                {
                    if (m==0) arr[i-1].hex[++m]='0';
                    break;
                }
                arr[i].hex[m]=s[j];
            }

            arr[i].hex[m]='\0';
        }
        for (j=arr[n-1].o+2,m=0;j<strlen(s);j++,m++)
        {
            if (s[j]>'f') break;
            arr[n-1].hex[m]=s[j];
        }
        arr[n-1].hex[m]='\0';
        int cnt=0;
        for (i=0;i<n;i++)
        {
            if (strlen(arr[i].hex)!=0)
                printf("%u%c",htoi(arr[i].hex),(i==n-1)?'\n':' ');
            if (strlen(arr[i].hex)==0)
                cnt++;
        }
        if (cnt==n)
            printf("-1\n");
        free(arr);
    }

    return 0;
}
