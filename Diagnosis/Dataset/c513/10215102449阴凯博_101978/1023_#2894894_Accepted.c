#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
typedef struct
{
    char str[40];
} STR;

int cmp(const void* a,const void* b)
{
    STR* pa=(STR*)a; STR* pb=(STR*)b;
    char s1[40]={0}; char s2[40]={0};
    int i,j=0;
    for (i=0;i<strlen(pa->str);i++)
    {
        if isdigit(pa->str[i])
            s1[j++]=pa->str[i];
    }
    s1[j]='\0';
    j=0;
    for (i=0;i<strlen(pb->str);i++)
    {
        if isdigit(pb->str[i])
            s2[j++]=pb->str[i];
    }
    s2[j]='\0';
    if (strlen(s1)==0 && strlen(s2)==0) return strcmp(pa->str,pb->str);
    if (strlen(s1)==0 && strlen(s2)!=0) return -1;
    if (strlen(s1)!=0 && strlen(s2)==0) return 1;

    int m=atoi(s1); int n=atoi(s2);
    if (m>n) return 1;
    if (m<n) return -1;
    if (m==n) return strcmp(pa->str,pb->str);
}

int main()
{
    char s[40];
    STR arr[100];
    int n=0;
    while (scanf("%s",s)!=EOF)
    {
        strcpy(arr[n++].str,s);
    }
    qsort(arr,n,sizeof(STR),cmp);
    for (int i=0;i<n;i++)
        printf("%s%c",arr[i].str,i==n-1?'\n':' ');
    return 0;
}
