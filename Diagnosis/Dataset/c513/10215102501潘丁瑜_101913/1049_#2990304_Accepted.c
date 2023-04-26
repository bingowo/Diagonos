#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct str
{
    char words[50];
};

int cmp(const void*a,const void*b)
{
    struct str *m=(struct str *)a;
    struct str *n=(struct str *)b;
    return strcmp(m->words,n->words);
}

int main()
{
    int T,i,j;
    char y;
    scanf("%d\n",&T);
    for(i=0;i<T;i++)
    {
        struct str s[501]={0};
        int k=0,l=0;
        while((y=getchar()) !='\n')
        {
            if(y==' ' || y=='!' || y=='?' || y=='.' || y==',')
            {
                if(s[k].words[0]) 
                    l=0,k++;
                else l=0;
            }
                
            else s[k].words[l++]=y;
        }
        qsort(s,k,sizeof(s[0]),cmp);
        printf("case #%d:\n",i);
        for(j=0;j<k && s[j+1].words[0];j++)
        {
            if(strcmp(s[j].words,s[j+1].words)!=0)
                printf("%s ",s[j].words);
        }
        if(strcmp(s[j].words,s[j+1].words)!=0)
                printf("%s\n",s[j].words);
    }

    return 0;
}