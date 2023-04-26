#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void*a,const void*b)
{
    char aa=*(char*)a,bb=*(char**)b;
    return strcmp(a,b);
}

void comb(char *s,char* char_comb)
{
    if(*s)
    {
        char left[17]={0};
        sprintf(left,"%s%c",char_comb,s[0]);
        printf("%s\n",left);
        comb(s+1,left);
        comb(s+1,char_comb);
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        int a[123]={0},count=0;
        char s[16]="",ss[16]="",char_comb[17]={0};
        scanf("%s",s);
        for(int i=0;i<strlen(s);i++)
        {
            if(a[s[i]]==0)
            {
                a[s[i]]=1;
                ss[count++]=s[i];
            }
        }
        qsort(ss,count,sizeof(ss[0]),cmp);
        printf("case #%d:\n",i);
        comb(ss,char_comb);
    }
    return 0;
}