#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char str[20];
    long long zhi;
}suiji;

long long fuzhi(char s[])
{
    int len=strlen(s);
    int a[128],i,k;
    memset(a,-1,128*sizeof(int));
    if(len==1) return 0;
    a[s[0]]=1;
    for(i=1,k=0;i<len;i++)
    {
        if(a[s[i]]==-1)
        {
            if(k==0) {a[s[i]]=k;k+=2;}
            else a[s[i]]=k++;
        }
    }
    if(k==0) k=2;
    long long re=0;
    for(i=0;i<len;i++)
    {
        re*=k;
        re+=a[s[i]];
    }
    /*printf("\n test: re=%d,s=%s,",re,s);
    printf("a=");
    for(i=0;i<len;i++)
    {
        printf("%d ",a[s[i]]);
    }
    printf("\n");*/
    return re;
}

int cmp(const void*a,const void*b)
{
    suiji aa=*((suiji*)a);
    suiji bb=*((suiji*)b);

    if(aa.zhi>bb.zhi) return 1;
    else if(aa.zhi<bb.zhi) return -1;
    else return strcmp(aa.str,bb.str);

}

int main()
{
    int t,i;
    scanf("%d",&t);
    suiji s[10010];
    memset(s,0,sizeof(suiji)*10010);
    for(i=0;i<t;i++)
    {
        scanf("%s",s[i].str);
        s[i].zhi=fuzhi(s[i].str);
    }
    qsort(s,t,sizeof(suiji),cmp);
    //printf("以下是结果\n");
    for(i=0;i<t;i++)
    {
        printf("%s\n",s[i].str);
    }
    return 0;
}
