#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
    char s[21];
    int num;
}CH;
int cmp(const void *p1,const void *p2)
{
    CH* a=p1;
    CH* b=p2;
    if((*a).num>(*b).num) return -1;
    else if((*a).num<(*b).num) return 1;
    else
        return strcmp((*a).s,(*b).s);
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        int n;
        scanf("%d",&n);
        CH a[100];
        for(int j=0;j<n;j++)
        {
            scanf("%s",a[j].s);
            char s2[21]={'0'};
            s2[0]=a[j].s[0];
            int q=1;
            for(int k=0;k<strlen(a[j].s);k++)
            {
                int e;
                for(e=0;e<q;e++)
                {
                    if(a[j].s[k]==a[j].s[e]) break;
                }
                if(e==q)
                {
                    s2[q]=a[j].s[k];
                    q++;
                }
            }
            a[j].num=q;
        }
        qsort(a,n,sizeof(CH),cmp);
        printf("case #%d:\n",i);
        for(int w=0;w<n;w++)
        {
            printf("%s\n",a[w].s);
        }
    }
}
