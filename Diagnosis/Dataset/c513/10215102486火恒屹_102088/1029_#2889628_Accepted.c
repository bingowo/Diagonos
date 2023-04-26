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
        char s[202]={'\0'};
        gets(s);
        char s0[202]={'\0'};
        for(int j=0;j<strlen(s);j++)
            s0[j]=s[j];
        //printf("s0:%s\n",s0);
        qsort(s,strlen(s),sizeof(s[0]),cmpfunc);
        //printf("s:%s\n",s);
        int q=0;
        for(int j=0;j<strlen(s);j++)
        {
            if ((s0[j]>'Z')||(s0[j]<'A'))
                printf("%c",s0[j]);
            else
            {
                while((s[q]>'Z')||(s[q]<'A'))
                    q++;
                printf("%c",s[q]);
                q++;
            }
        }
        printf("%c",10);
    }

    return 0;
}
