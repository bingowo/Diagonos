#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct words
{
    char s1[2000];
    int lenth;
    int blank_num;
};

int main()
{
    int T,i;
    scanf("%d ",&T);
    for(i=0;i<T;i++)
    {
        int M,j,p1=0,p2=0,l1,l=0,j1,word_number,total_blank_num;
        int j3,j4;
        char s[2001]={0};
        struct words c[2000];
        scanf("%d ",&M);
        gets(s);
        l1=strlen(s);
        printf("case #%d:\n",i);
        for(j=0;j<l1;j++)
        {
            if(s[j]!=' ')
                c[p1].s1[p2++]=s[j];
            else
            {
                c[p1].lenth=p2;
                p1++;p2=0;
            }
        }
        for(j=0,j1=0;j1<p1;j1++)
        {
            l=l+c[j1].lenth+1;
            if((l+c[j1+1].lenth)>M)
            {
                word_number=j1;
                total_blank_num=M-l;l=0;
                for(j3=0;j3<word_number;j3++)
                    c[j3].blank_num=total_blank_num/(word_number-1);
                if(total_blank_num%(word_number-1)!=0)
                    {
                        int last_blank=total_blank_num%(word_number-1);
                        for(j4=word_number-1;last_blank>0;j4--,last_blank--)
                            c[j4].blank_num++;
                    }
                for(;j<word_number;j++)
                {
                    printf("%s",c[j].s1);
                    for(j3=0;j3<c[j].blank_num;j3++)
                        printf(" ");
                }
                j=j1+1;
                printf("\n");
            }
        }
    }
}