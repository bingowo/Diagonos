#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp(const void *a,const void *b)
{
    char s1=*(char*)a,s2=*(char*)b;
    if(s1>s2) return 1;
    else return -1;
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        char s[1000];
        scanf("%s",s);
        int len=strlen(s);
        qsort(s,len,sizeof(char),cmp);
        printf("case #%d:\n",i);
        for(int j=0;j<len;j++)
        {
            int num=0;
            for(int k=j;k<len;k++)
            {
                if(s[k]==s[j]) num++;
                if(s[k]!=s[j])
                {
                    while(num>255)
                    {
                        printf("255%c",s[j]);
                        num-=255;
                    }
                    if(num<=255&&num>0) {printf("%d%c",num,s[j]);j=j+num-1;break;}
                    else if(num==0) break;
                }
            }
        }
        printf("\n");
    }
    return 0;
}
