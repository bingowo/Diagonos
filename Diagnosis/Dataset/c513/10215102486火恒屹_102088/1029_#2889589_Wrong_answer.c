#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmpfunc (const void * a, const void * b)
{
   return ( *(char*)a - *(char*)b );
}
int main()
{
    int quesnum;
    scanf("%d\n",&quesnum);
    for(int i=0;i<quesnum;i++)
    {
        printf("case #%d:\n",i);
        char s[102]={'\0'};
        gets(s);
        char s0[102]={'\0'};
        for(int j=0;j<strlen(s);j++)
            s0[j]=s[j];
        qsort(s,strlen(s),sizeof(s[0]),cmpfunc);
        int q=0;
        while(s[q]==32)
            q++;
        for(int j=0;j<strlen(s);j++)
        {
            if (s0[j]==32)
                printf(" ");
            else
            {
                printf("%c",s[q]);
                q++;
            }
        }
    }

    return 0;
}
