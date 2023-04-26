#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


typedef struct
{
    char str[40];
} STR;

int cmp(const void* a,const void* b)
{
    char* pa=(char*)a; char* pb=(char*)b;
    if (isalpha(*pa) && isalpha(*pb)) return *pa>*pb?1:-1;
    if (isalpha(*pa) && !isalpha(*pb)) return -1;
    if (!isalpha(*pa) && isalpha(*pb)) return 1;
}

int main()
{
    int T;
    scanf("%d",&T);
    for (int i=0;i<T;i++)
    {
        printf("case #%d:\n",i);
        char s[220],s1[220];
        STR arr[220];
        int n=0,i,j,k=0,m;
        while (scanf("%s",s)!=EOF)
        {
            strcpy(arr[n++].str,s);
        }
        for (i=0;i<n;i++)
        {
            for (j=0;j<strlen(arr[i].str);j++)
                s1[k++]=arr[i].str[j];
        }
        s1[k]='\0';
        printf("%s\n",s1);
        qsort(s1,k,sizeof(char),cmp);
        printf("%s\n",s1);
        i=0;j=0;m=0;
        for (j=0;j<n;j++)
        {
            for (m=0;m<strlen(arr[j].str);m++)
            {
                if (isalpha(arr[j].str[m]))
                    arr[j].str[m]=s1[i++];
            }
        }
        for (i=0;i<n;i++)
            printf("%s%c",arr[i].str,i==n-1?'\n':' ');



    }
    return 0;
}
