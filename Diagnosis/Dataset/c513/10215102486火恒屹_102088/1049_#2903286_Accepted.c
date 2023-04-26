#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp(const void *a,const void *b)
{
    return strcmp((char *)a,(char *)b);
}
int main()
{
    int T;
    scanf("%d\n",&T);
    for(int i=0;i<T;i++)
    {
        printf("case #%d:\n",i);
        char word[500][20]={'\0'};
        int count1=0;
        int count2=0;
        char a;
        while((a=getchar())!=10)
        {
            if((a>='a')&&(a<='z'))
            {
                word[count1][count2]=a;
                count2++;
                while(((a=getchar())>='a')&&(a<='z'))
                {
                    word[count1][count2]=a;
                    count2++;
                }
                count1++;
                count2=0;
                ungetc(a,stdin);
            }
        }
        qsort(word,count1,sizeof(word[0]),cmp);
        printf("%s ",word[0]);
        for(int j=1;j<count1;j++)
        {
            if(strcmp(word[j],word[j-1])!=0)
                printf("%s ",word[j]);
        }
        printf("%c",10);
    }
    return 0;
}
