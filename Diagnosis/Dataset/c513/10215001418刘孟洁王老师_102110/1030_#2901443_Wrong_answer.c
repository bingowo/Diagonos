#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#define  N  10001

typedef struct{long long int number;int max;}high;

int cmp(const void*a,const void*b)
{
    high c=*(high*)a;
    high d=*(high*)b;
    if(c.max==d.max)
    {
        if(c.number<d.number)return -1;
        else return 1;
    }
    else return d.max-c.max;
}


int main()
{
    int n,cas,i,j,k,a;
    high *s;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&cas);
        s=(high*)malloc(sizeof(high)*cas);
        for(j=0;j<cas;j++)
        {
            scanf("%lld",&s[j].number);
            a=s[j].number;
            if(llabs(a)>=10)
            {
                while(llabs(a)>=10)
                 {
                    a=a/10;
                    k=a;
                 }
            }
            else k=a;
            s[j].max=llabs(k);
        }
        qsort(s,cas,sizeof(high),cmp);
        printf("case #%d:\n",i);
        for(j=0;j<cas;j++)printf("%lld%c",s[j].number,j==cas-1?'\n':' ');
        free(s);

    }
    return 0;
}
