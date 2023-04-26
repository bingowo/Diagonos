#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 120

typedef struct
{
    char str[MAX];
} STR;


void simp(char* s)
{
    int i,j;
    char s1[MAX]={0};
    if (s[0]=='0')
    {
        for (i=0;i<strlen(s);i++)
            if (s[i]!='0')
                break;
        for (i,j=0;i<strlen(s);i++,j++)
        {
            s[j]=s[i];
        }
        s[j]='\0';
    }
    else;
}


int cmp(const void* a,const void* b)
{
    STR* pa=(STR*)a; STR* pb=(STR*)b;
    int i,j;
    if (strlen(pa->str)>strlen(pb->str)) return -1;
    if (strlen(pb->str)>strlen(pa->str)) return 1;
    if (strlen(pb->str)==strlen(pa->str))
    {
        for (i=0;i<strlen(pb->str);i++)
            return (pa->str[i]>pb->str[i])?-1:1;
    }

}

int main()
{
    char s[MAX]={0};
    scanf("%s",s);
    int i,n=0,j=0,m=0,flag=0;
    for (i=1;i<strlen(s);i++)
    {
        if (isalpha(s[0]))
            flag=1;
        if (flag==0)
        {
            if (isalpha(s[i]) && isdigit(s[i-1]))
            {
                n++;
                flag++;
            }
        }
        else
            if (isdigit(s[i]) && isalpha(s[i-1]))
                n++;
    }
    if (flag==0)
        n++;
    STR* arr=(STR*)malloc(n*sizeof(STR));
    for (i=0;i<strlen(s);i++)
    {
        if (isdigit(s[i]))
        {
            while (1)
            {
                arr[j].str[m++]=s[i++];
                if (isalpha(s[i]))
                {
                    arr[j].str[m]='\0';
                    j++;
                    m=0;
                    break;
                }
            }
        }
    }
    for (i=0;i<n;i++)
        simp(arr[i].str);
    qsort(arr,n,sizeof(STR),cmp);
    printf("%d\n",strlen(arr[0].str));




    return 0;
}
