#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct words
{
    char s1[20];
};

int cmp(const void*a,const void*b)
{
    struct words*ap=(struct words*)a;
    struct words*bp=(struct words*)b;
    return(strcmp(ap->s1,bp->s1)>0);
}

void single(struct words *s,int p)
{
    int i,j,k;
    int l1,l2,l;
    for(i=1;i<p;i++)
    {
        for(j=0;j<i;j++)
        {
            l=0;
            l1=strlen(s[i].s1);
            l2=strlen(s[j].s1);
            if(l1==l2)
            {
                for(k=0;s[i].s1[k]&&s[j].s1[k];k++)
                {
                    if(s[i].s1[k]==s[j].s1[k])
                            l=l+1;
                }
                if(l==l1)
                {
                    for(k=0;k<l1;k++)
                        s[i].s1[k]=0;
                }
        }
    }
}
}

int main()
{
    int T;
    scanf("%d ",&T);
    int i;
    for(i=0;i<T;i++)
    {
        char s[501]={0};
        gets(s);
        struct words s2[500]={0};
        int j,p=1,q;
        for(j=0;s[j]!=' '&&s[j]!=','&&s[j]!='.'&&s[j]!='!'&&s[j]!='?'&&s[j];j++)
            s2[0].s1[j]=s[j];
        s2[0].s1[j]=0;
        j++;
        for(;s[j];j++)
        {
            if(s[j]==','||s[j]=='.'||s[j]=='!'||s[j]=='?'||s[j]==' ');
            else
            {
                for(q=0;s[j]!=' '&&s[j]!=','&&s[j]!='.'&&s[j]!='!'&&s[j]!='?';j++,q++)
                    s2[p].s1[q]=s[j];
                s2[p].s1[q]=0;
                p++;
            }
        }
        single(s2,p);
        qsort(s2,p,sizeof(struct words),cmp);
        printf("case #%d:\n",i);
        for(j=0;j<p;j++)
        {
            for(q=0;s2[j].s1[q]!=0;q++)
                printf("%c",s2[j].s1[q]);
            if(q==0);
            else
                printf(" ");
        }
        printf("\n");
    }
}