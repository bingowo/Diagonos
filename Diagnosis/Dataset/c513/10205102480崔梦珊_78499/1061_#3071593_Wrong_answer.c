#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct str
{
    char s[20];
    long long num;
};
long long cmp(const void* a,const void* b)
{
    struct str* x=(struct str*)a;
    struct str* y=(struct str*)b;
    if(x->num==y->num) return strcmp(x->s,y->s);
    return x->num-y->num;
}

int main()
{
    int n;
    scanf("%d",&n);
    struct str ans[10000];
    for(int i=0;i<n;i++)
    {
        int flag[200]={0};
        scanf("%s",ans[i].s);
        long long len=strlen(ans[i].s);
        long long sign[200]={0};
        long long cnt=1;
        for(int j=0;j<len;j++)
        {
            if(flag[ans[i].s[j]]==0)
            {
                if(cnt==1)
                {
                    sign[ans[i].s[j]]=cnt;
                    cnt=0;
                    flag[ans[i].s[j]]=1;
                    continue;
                }
                if(cnt==0)
                {
                    sign[ans[i].s[j]]=cnt;
                    cnt=2;
                    flag[ans[i].s[j]]=1;
                    continue;
                }
                else
                {
                    sign[ans[i].s[j]]=cnt;
                    cnt++;
                    flag[ans[i].s[j]]=1;
                }
            }
        }
        int n=0;
        for(int j=0;j<200;j++)
        {
            n+=flag[j];
        }
        if(n==1) n=2;
        ans[i].num=0;
        /*for(int j=0;j<len;j++)
        {
            printf("%d ",sign[ans[i].s[j]]);
        }
        printf("\n");*/
        for(int j=0;j<len;j++)
        {
            ans[i].num=ans[i].num*n+sign[ans[i].s[j]];
            /*printf("%lld\n",ans[i].num);*/
        }
    }
    qsort(ans,n,sizeof(ans[0]),cmp);
    /*for(int i=0;i<n;i++)
    {
        printf("%d\n",ans[i].num);
    }*/
    for(int i=0;i<n;i++)
    {
        printf("%s\n",ans[i].s);
    }
}
