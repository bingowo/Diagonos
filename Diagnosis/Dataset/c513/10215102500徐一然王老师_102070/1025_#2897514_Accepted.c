#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct SSS{char s[30];int n;}JIE;

int cmp(const void*a,const void*b)
{
    JIE* p1=(JIE*)a;
    JIE* p2=(JIE*)b;
    if(p1->n<p2->n)
    {
        return 1;
    }
    else if(p1->n>p2->n)
    {
        return -1;
    }
    else return strcmp(p1->s,p2->s);
}

int main()
{
    int count,count1,num,n,num1=0;
    scanf("%d",&count);
    count1=count;
    while(count--)
    {
        JIE S[100];
        JIE*p=S;
        scanf("%d",&num);

        for(int i=0;i<num;i++)
        {
            scanf("%s",&S[i].s);
            n=strlen(S[i].s);
        for(int k=0;k<n;k++)
        {int j=0;
        for(;j<k;j++)
        if(S[i].s[k]==S[i].s[j]) break;
        if(j>=k) num1++;
        }
        S[i].n=num1;
        num1=0;
        }
        qsort(p,num,sizeof(S[0]),cmp);
        printf("case #%d:\n",count1-count-1);
        for(int i=0;i<num;i++)
        {
            printf("%s\n",S[i].s);
        }
    }

}
