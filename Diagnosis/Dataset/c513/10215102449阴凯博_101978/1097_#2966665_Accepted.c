#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char a;
    int line;
    int space;
} CHAR;

int cmp(const char* a,const char* b)
{
    CHAR* pa=(CHAR*)a; CHAR* pb=(CHAR*)b;
    if (pa->line>pb->line) return -1;
    if (pa->line<pb->line) return 1;
    if (pa->line==pb->line)
    {
        return (pa->space>pb->space)?1:-1;
    }
}

void emptty(char* s)
{
    for (int i=0;i<100;i++)
        s[i]='\0';
}

int main()
{
    char s[100]={0};
    while (scanf("%s",s)!=EOF)
    {
        int len=strlen(s);
        CHAR* arr=(CHAR*)malloc(len*sizeof(CHAR));
        for (int i=0;i<len;i++)
        {
            arr[i].a=s[i];
            arr[i].space=i;
            if (i==0)
                arr[i].line=1;
            else
            {
                if (s[i]>s[i-1])
                    arr[i].line=arr[i-1].line+1;
                if (s[i]<s[i-1])
                    arr[i].line=arr[i-1].line-1;
                if (s[i]==s[i-1])
                    arr[i].line=arr[i-1].line;
            }
        }
        qsort(arr,len,sizeof(CHAR),cmp);
        char s1[80]={0};
        if (len==1)
            printf("%c\n",s[0]);
        if (len>1)
        {
            for (int i=0;i<len;i++)
            {

                if (i==0)
                {
                    s1[arr[i].space]=arr[i].a;
                }
                else if (i<len-1)
                {
                    if (arr[i].line==arr[i-1].line)
                        s1[arr[i].space]=arr[i].a;
                    if (arr[i].line!=arr[i-1].line)
                    {
                        for (int j=0;j<arr[i-1].space;j++)
                            if (s1[j]=='\0')
                                s1[j]=' ';
                        printf("%s\n",s1);
                        emptty(s1);
                        s1[arr[i].space]=arr[i].a;
                    }
                }
                if (i==len-1)
                {
                    if (arr[i].line==arr[i-1].line)
                    {
                        s1[arr[i].space]=arr[i].a;
                        for (int j=0;j<arr[i].space;j++)
                            if (s1[j]=='\0')
                                s1[j]=' ';
                        printf("%s\n",s1);
                        emptty(s1);
                    }
                    if (arr[i].line!=arr[i-1].line)
                    {
                        for (int j=0;j<arr[i-1].space;j++)
                            if (s1[j]=='\0')
                                s1[j]=' ';
                        printf("%s\n",s1);
                        emptty(s1);
                        s1[arr[i].space]=arr[i].a;
                        for (int j=0;j<arr[i].space;j++)
                            if (s1[j]=='\0')
                                s1[j]=' ';
                        printf("%s\n",s1);
                        emptty(s1);
                    }
                }
            }

        }

    }
    return 0;
}
