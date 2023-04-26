#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char strlwr(char c)
{
    if(c<97)c=c+32;
    return c;
}

struct st
{
    char str[21];
    char str1[21];
};

int cmp(const void*a,const void *b)
{
    struct st*c=(struct st*)a;
    struct st*d=(struct st*)b;
    return strcmp(c->str1,d->str1);
}

int main()
{
    char prime[27];char b[200];
    while(scanf("%s",prime)!=EOF)
    {
        struct st chr[100];int i,j;
        for(i=0;i<27;i++)b[prime[i]+32]='a'+i;
        i=0;
        scanf("%s",chr[i].str);
        for(j=0;j<strlen(chr[i].str);j++)chr[i].str1[j]=b[strlwr(chr[i].str[j])];
        i++;
        while(getchar()!='\n')
        {
            scanf("%s",chr[i].str);
            for(j=0;j<strlen(chr[i].str);j++)chr[i].str1[j]=b[strlwr(chr[i].str[j])];
            i++;
        }
        qsort(chr,i,sizeof(struct st),cmp);
        for(j=0;j<i-1;j++)printf("%s ",chr[j].str);
        printf("%s\n",chr[j].str);
    }
    
    
}