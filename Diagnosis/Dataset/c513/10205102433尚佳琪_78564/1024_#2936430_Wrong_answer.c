#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    long long int name;
    int sum;
}NAME;
int cmp(const void *a,const void *b)
{
    NAME s1=*(NAME *)a;
    NAME s2=*(NAME *)b;
    if(s2.sum!=s1.sum)
        return s2.sum-s1.sum;
    else
        return s1.name-s2.name;
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        int n,m,g;
        scanf("%d %d %d",&n,&m,&g);
        int a[m];
        NAME ans[n];
        int num=0;
        for(int i=0;i<m;i++)
            scanf("%d",&a[i]);
        for(int j=0;j<n;j++)
        {
            scanf("%lld %d",&ans[j].name,&num);
            int b[num],temp=0;
            for(int i=0;i<num;i++)
            {
                scanf("%d",&b[i]);
                temp=temp+a[b[i]-1];
            }
            ans[j].sum=temp;
        }
        qsort(ans,n,sizeof(ans[0]),cmp);
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(ans[i].sum>=g)
                cnt++;
                //printf("%s %d\n",ans[i].name,ans[i].sum);
        }
        printf("case #%d:\n%d\n",i,cnt);
        for(int i=0;i<n;i++)
        {
            if(ans[i].sum>=g)
                printf("%lld %d\n",ans[i].name,ans[i].sum);
        }
    }
    return 0;
}
