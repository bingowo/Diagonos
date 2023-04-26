#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000020

typedef struct
{
    int order;
    char str[70];

} STRR;

int cmp (const void* a,const void* b)
{
    STRR* pa=(STRR*)a; STRR* pb=(STRR*)b;
    if (strlen(pa->str)>strlen(pb->str)) return -1;
    if (strlen(pa->str)<strlen(pb->str)) return 1;
    if (strlen(pa->str)==strlen(pb->str))
    {
        return (pa->order>pb->order)?1:-1;
    }
}

int main()
{
    char s[MAX]={0};
    char s1[100]={0};
    int i,j=0,k=0,n=0;
    scanf("%s",s);
    n=strlen(s);
    STRR* arr=(STRR*)calloc((MAX/70),sizeof(STRR));
    for (i=1;i<strlen(s);i++)
    {
        if (s[i]!=s[i-1])
        {
            arr[j].order=i-1;
            arr[j].str[k++]=s[i-1];
            while (s[i]!=s[i-1])
            {
                if (!strchr(arr[j].str,s[i]))
                    arr[j].str[k++]=s[i];
                else
                {
                    arr[j].str[k]='\0';
                    j++;
                    break;
                }
                i++;
            }
            k=0;
        }
    }
    if (strlen(s)==1)
        strcpy(arr[0].str,s);
    qsort(arr,j,sizeof(STRR),cmp);
    printf("%s\n",arr[0].str);
    free(arr);
    return 0;
}
