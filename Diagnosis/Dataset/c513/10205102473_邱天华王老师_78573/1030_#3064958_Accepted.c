#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define ll long long 
typedef struct NUM
{
    char s[20];
    int k;
    ll n;
}num;
int cmp(const void* q1,const void* q2)
{
    num* a=(num* )q1;
    num* b=(num* )q2;
    if(a->k!=b->k)
        return (b->k-a->k);
    else 
        return (a->n>b->n?1:-1);
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        int m;
        scanf("%d",&m);
        num* ss;
        ss=(num* )malloc(sizeof(num)*m);
        for(int j=0;j<m;j++)
        {
            scanf("%s",&ss[j].s);
            int len=strlen(ss[j].s);
            //printf("len=%d s=%s\n",len,ss[j].s);
            ss[j].n=0;
            if(ss[j].s[0]=='-')
            {
                ss[j].k=ss[j].s[1]-'0';
                for(int l=1;l<len;l++)
                {
                    ss[j].n=ss[j].n*10+ss[j].s[l]-'0';
                }
                ss[j].n=-ss[j].n;
            }
            else 
            {    
                ss[j].k=ss[j].s[0]-'0';
                for(int l=0;l<len;l++)
                {
                    ss[j].n=ss[j].n*10+ss[j].s[l]-'0';
                }
            }            
        }
        
        qsort(ss,m,sizeof(ss[0]),cmp);
        printf("case #%d:\n",i);
        for(int h=0;h<m;h++)
        {
            printf("%lld ",ss[h].n);
        }
        free (ss);
        printf("\n");
    }
    return 0;
}