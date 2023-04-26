#include <stdio.h>
#include <stdlib.h>


int s[1001]={0};
int res[1001]={0};
int cmp(const void*p1,const void*p2)
{
    int a = *(int*)p1;
    int b = *(int*)p2;
    if(s[a]==0&&s[b]==0)return (a<b)?-1:1;
    else if(s[a]==0)return 1;
    else if(s[b]==0)return -1;
    else if(s[a]>=s[b])return 1;
    else return -1;
}

int main()
{
    int m;

    scanf("%d",&m);
    for(int i =1;i<=m;i++)
    {
        int q;
        scanf("%d",&q);
        s[q] = i;
    }

    int n;
    scanf("%d",&n);
    for(int i =0;i<n;i++)
    {
        scanf("%d",&res[i]);
    }
    qsort(res,n,sizeof(int),cmp);
    for(int z =0;z<n;z++)
    {
        printf("%d",res[z]);
        if(z!=n-1)printf(" ");
    }
    return 0;
}
