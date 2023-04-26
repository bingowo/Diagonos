#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct st
{
    char chr[15];
};

int cmp(const void*a,const void*b)
{
    return strcmp((*(struct st*)a).chr,(*(struct st*)b).chr);
}

int main()
{
    int T;scanf("%d\n",&T);char c;
    for(int t=0;t<T;t++)
    {
        printf("case #%d:\n",t);
        struct st s[50];int i=0,j=0,k;
        while((c=getchar())!='\n')
        {
            if(c==' '||c==','||c=='.'||c=='!'||c=='?')
            {s[i].chr[j]='\0';i++;j=0;}
            else
                s[i].chr[j++]=c;
        }
        qsort(s,i,sizeof(s[0]),cmp);
        printf("%s",s[0]);
        for(j=1;j<i;j++)
            if(strcmp(s[j].chr,s[j-1].chr)!=0)printf(" %s",s[j]);
        printf("\n");
    }
}
