#include <stdio.h>
#include <stdlib.h>

struct str
{
    char s[100];
    int count;
};
int cmp(const void*a,const void*b)
{
    struct str *c=(struct str *)a;
    struct str *d=(struct str *)b;
    int i=0;
    if(c->count != d->count)
        return d->count - c->count;
    else
    {
        while(c->s[i] && d->s[i])
        {
            if(c->s[i] != d->s[i])
                return c->s[i] - d->s[i];
            else i++;
        }
        if(c->s[i] == 0) return -1;
        else return 1;

    }
}

int main()
{
    int T,P;
    scanf("%d\n",&T);
    int i,j,r;
    char c;
    for(i=0;i<T;i++)
    {
        struct str S[1000]={0};
        scanf("%d\n",&P);
        for(j=0;j<P;j++)
        {
            r=0;
            int repeat[1000]={0};
            c=getchar();
            while(c!='\n')
            {
                S[j].s[r++]=c;
                if(repeat[c-'A']==0) S[j].count++;
                repeat[c-'A']=1;
                c=getchar();
            }
            //S[j].s[r]='\0';
        }
        qsort(S,j,sizeof(S[0]),cmp);
        printf("case #%d:\n",i);
        for(j=0;j<P;j++)
            printf("%s\n",S[j].s);
    }
    return 0;
}