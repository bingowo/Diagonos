#include<stdio.h>
#include<math.h>

int cmp(int a,int b)
{
    if(a>b) return 1;
    else return -1;
}

int main()
{
    int n;
    scanf("%d",&n);
    int L[100]={0};
    for(int i=0;i<n;i++)
    {
        scanf("%d",&L[i]);
        L[i]=abs(L[i]);
    }
    qsort(L,n,sizeof(int),cmp);
    long long ans=0;
    for(int i=0;i<n;i++)
    {
        if(i%2==0) ans+=(-1)*L[i];
        else ans+=L[i];
    }
    printf("%lld",ans);
    return 0;
}
