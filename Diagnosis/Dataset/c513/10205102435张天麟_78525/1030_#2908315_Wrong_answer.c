#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct
{
    char s[20];
    int t;
    int zf;
}zhengshu;
int cmp(const void *a,const void *b)
{
    int ta=((zhengshu*)a)->t,tb=((zhengshu*)b)->t;
    int ca=((zhengshu*)a)->zf,cb=((zhengshu*)b)->zf;
    if(ta!=tb)return tb-ta;
    else
    {
        if(ca!=cb)return ca-cb;
        else 
        {
            if(ca<0)return strcmp(((zhengshu*)b)->s,((zhengshu*)a)->s);
            else return strcmp(((zhengshu*)a)->s,((zhengshu*)b)->s);
        }
    }
}
int main()
{
    int T,N;
    scanf("%d",&T);
    for(N=0;N<T;N++)
    {
        int n,i;
        scanf("%d",&n);
        zhengshu zs[n];
        for(i=0;i<n;i++)
        {
            scanf("%s",zs[i].s);
            if(zs[i].s[0]=='-')
            {
                zs[i].t=zs[i].s[1]-'0';
                zs[i].zf=-1;
            }
            else
            {
                zs[i].t=zs[i].s[0]-'0';
                zs[i].zf=1;
            }
        }
        qsort(zs,n,sizeof(zs[0]),cmp);
        printf("case #%d:\n",N);
        for(i=0;i<n;i++)
        {
            printf("%s ",zs[i].s);
        }
        printf("\n");
    }
    return 0;
}
