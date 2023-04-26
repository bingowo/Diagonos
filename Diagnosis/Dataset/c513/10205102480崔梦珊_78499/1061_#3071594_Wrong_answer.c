#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef unsigned long long ll;
struct str
{
    char s[20];
    ll num;
};
ll cmp(const void* a,const void* b)
{
    struct str* x=(struct str*)a;
    struct str* y=(struct str*)b;
    if(x->num==y->num) return strcmp(x->s,y->s);
    return x->num-y->num;
}

int main()
{
    ll n;
    scanf("%llu",&n);
    struct str ans[10000];
    for(ll i=0;i<n;i++)
    {
        ll flag[200]={0};
        scanf("%s",ans[i].s);
        ll len=strlen(ans[i].s);
        ll sign[200]={0};
        ll cnt=1;
        for(ll j=0;j<len;j++)
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
        ll ni=0;
        for(ll j=0;j<200;j++)
        {
            ni+=flag[j];
        }
        if(ni==1) ni=2;
        ans[i].num=0;
        /*for(int j=0;j<len;j++)
        {
            printf("%d ",sign[ans[i].s[j]]);
        }
        printf("\n");*/
        for(ll j=0;j<len;j++)
        {
            ans[i].num=ans[i].num*ni+sign[ans[i].s[j]];
            /*printf("%lld\n",ans[i].num);*/
        }
    }
    qsort(ans,n,sizeof(ans[0]),cmp);
    /*for(int i=0;i<n;i++)
    {
        printf("%d\n",ans[i].num);
    }*/
    for(ll i=0;i<n;i++)
    {
        printf("%s\n",ans[i].s);
    }
}
