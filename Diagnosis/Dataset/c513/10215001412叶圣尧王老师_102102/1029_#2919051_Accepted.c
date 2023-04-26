#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int cmp(const void*a,const void *b)
{
    return *(char*)a-*(char*)b;
}

int main()
{
    int T,i;scanf("%d",&T);getchar();
    for(i=0;i<T;i++)
    {
        char s[200];char chr[200];int j,k=0;
        for(j=0;(s[j]=getchar())!='\n';j++)
            if(s[j]>='A'&&s[j]<='Z'){chr[k++]=s[j];s[j]='A';}
        
        qsort(chr,k,sizeof(chr[0]),cmp);
        k=0;int e;
        printf("case #%d:\n",i);
        for(e=0;e<j;e++)
        if(s[e]=='A')printf("%c",chr[k++]);
        else printf("%c",s[e]);
        printf("\n");
    }
}