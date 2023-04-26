#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <ctype.h>
#include <stdlib.h>

int cmp(const void*a,const void *b)
{
    return strcmp(*(char*)a,*(char*)b);
}

int main()
{
    int count,count1;
    scanf("%d\n",&count);
    count1=count;
    char S[501];
    while(count--)
    {
        int j,i;
        char* p1=S;
        gets(S);
        char copy[100][100];
        for(int k=0;k<100;k++)
        {
            for(int l=0;l<100;l++)
            {
                copy[k][l]='\0';
            }
        }
            for(j=0;*p1;j++)
            {
                for(i=0;isalpha(*p1)&&(*p1);i++)
                {
                    copy[j][i]=*p1;p1++;

                }
                while(!isalpha(*p1)&&(*p1))
                {
                    p1++;

                }
            }
        qsort(copy,j,sizeof(copy[0]),cmp);
        printf("case #%d:\n",count1-count-1);
        for(int i=0;i<j+1;i++)
        {
            if(i==j)
               printf("\n");
            if(!strcmp(copy[i+1],copy[i]))
            {
                continue;
            }

            printf("%s ",copy[i]);


        }

    }

}
