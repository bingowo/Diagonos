#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct st 
{
    char chr;
    float f;
};

int cmp(const void*a,const void*b)
{
    struct st*c=(struct st*)a;
    struct st*d=(struct st*)b;
    if(c->f==d->f)return d->chr-c->chr;
    else if(c->f>d->f)return -1;
    else return 1;
}

int main()
{
    int T,t;scanf("%d",&T);
    for(t=0;t<T;t++)
    {
        int j;float fp[26];char s1[101];
        for(j=0;j<26;j++)
            scanf("%f",&fp[j]);
        scanf("%s",s1);
        struct st s[strlen(s1)];
        for(j=0;j<strlen(s1);j++)
        {
            s[j].chr=s1[j];
            if(s1[j]>='A'&&s1[j]<='Z')s[j].f=fp[s1[j]-'A'];
            else s[j].f=fp[s1[j]-'a'];
        }
        qsort(s,strlen(s1),sizeof(s[0]),cmp);
        printf("case #%d:\n",t);
        for(j=0;j<strlen(s1);j++)printf("%c",s[j].chr);
        printf("\n");
    }
}