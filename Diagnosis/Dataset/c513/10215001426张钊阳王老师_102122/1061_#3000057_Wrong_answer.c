#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
struct n{
    char s[20];
    long long sum;
};struct n m[10001];

int main()
{
    long long solve(char *s,int l);
    int cmp0(const void* a1,const void *b1);
    int n;
    scanf("%d",&n);
    for(int z=0;z<n;z++)
    {
        scanf("%s",m[z].s);
    }

    for(int j=0;j<n;j++)
    {
        int l0=strlen(m[j].s);

        m[j].sum=solve(m[j].s,l0);
    }

    qsort(m,n,sizeof(m[0]),cmp0);

    for(int k=0;k<n;k++)
        printf("%s\n",m[k].s);

    return 0;
}


long long solve(char *s,int l)
{
    long long trans(int *s,int l,int cnt);
    int cmp(const void* a1,const void *b1);
    int i;
    int cnt=0;
    int l0=0;
    int n[128]={0};
    for(i=0;i<l;i++)
    {
        n[s[i]]++;
        l0++;
    }
    for(int z=0;z<128;z++)
    {
        if(n[z]!=0) cnt++;
    }
    int nn=cnt;//n为进制数 字符代表最大数为n-1

    int ans[20];
    qsort(n,128,sizeof(int),cmp);

    int j;
    int sit=0;

    if(n[0]==1)
    {
        int m=2;
        ans[0]=1;
        n[0]--;
        sit++;
        if(n[1]!=0)
        {
            while(n[1]>0)
            {
                ans[sit++]=0;
                n[1]--;
            }

            for(j=2;j<nn;j++)
            {
                while(n[j]>0)
                {
                    ans[sit++]=m;
                    n[j]--;
                }
                m++;
            }
        }
    }
    else if(n[0]>1)
    {
        int m=2;
        while(n[0]>0)
        {
            ans[sit++]=1;
            n[0]--;
        }

        if(n[1]!=0)
        {
            while(n[1]>0)
            {
                ans[sit++]=0;
                n[1]--;
            }
            for(j=2;j<nn;j++)
            {
                while(n[j]>0)
                {
                    ans[sit++]=m;
                    n[j]--;
                }
                m++;
            }
        }
    }
    long long ans0=trans(ans,l0,cnt);

    return ans0;

}

int cmp(const void* a1,const void *b1)
{
    int a=*(int *)a1;
    int b=*(int *)b1;
    return b-a;
}

int cmp0(const void* a1,const void *b1)
{
    struct n a=*(struct n*)a1;
    struct n b=*(struct n*)b1;
    if(a.sum>b.sum) return 1;
    if(a.sum==b.sum) return strcmp(a.s,b.s);
    if(a.sum<b.sum) return -1;
}


long long trans(int *s,int l,int cnt)
{
    int i=0;
    long long sum=0;
    for(i=l-1;i>=0;i--)
    {
        sum+=s[i]*pow(cnt,l-1-i);
    }
    return sum;
}
