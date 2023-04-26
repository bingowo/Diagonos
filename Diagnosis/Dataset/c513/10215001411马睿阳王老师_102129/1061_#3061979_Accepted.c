#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct
{
    char s[17];long long val;
}num;

int cmp(const void*a,const void*b)
{
    num c=*(num*)a;
    num d=*(num*)b;
    if(c.val<d.val) return -1;
    else if(c.val>d.val) return 1;
    else if(strcmp(c.s,d.s)<0) return -1;//注意字典顺序要用strcmp
    else return 1;
}

int main()
{
    int n,i,j;
    long long p[128];
    num t[10007];
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%s",t[i].s);
    for(i=0;i<n;i++)
    {
        t[i].val=0;
        for(j=0;j<128;j++) p[j]=-1;
        int l=strlen(t[i].s);
        p[t[i].s[0]]=1;
        long long digit=0;
        for(j=1;j<l;j++)
        {
            if(p[t[i].s[j]]==-1)
            {
                p[t[i].s[j]]=digit;
                digit=digit==0?2:digit+1;
            }
        }
        digit=digit>2?digit:2;//没有一进制
        for(j=0;j<l;j++)
            t[i].val=t[i].val*digit+p[t[i].s[j]];
    }
    qsort(t,n,sizeof(t[0]),cmp);
    for(i=0;i<n;i++)
        printf("%s\n",t[i].s);
    return 0;
}
