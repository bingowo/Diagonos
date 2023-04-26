#include <stdio.h>
#include <stdlib.h>

int getAns(int L[],int len)
{
    int ans = 0;
    int i = 0;
    for(int i = 0;i<len;i+=2)
    {
        ans+=nabs(L[i],L[i+1]);
    }
    return ans;

}

int nabs(int a,int b)
{
    int ans = a-b;
    if(ans<0){return -1*ans;}
    else{return ans;}
}

int cmp(const void *a,const void *b)
{
    int A = *(int*)a,B = *(int*)b;
    return A-B;
}

int main()
{
    int n = 0,ans = 0;
    scanf("%d",&n);
    int L[n];memset(L,0,n*sizeof(int));

    for(int i = 0;i<n;i++)
    {
        scanf("%d",&L[i]);
    }

    qsort(L,n,sizeof(L[0]),cmp);
    ans = getAns(L,n);
    printf("%d",ans);
    //for(int i = 0;i<n;i++)
    //{
    //    printf("%d ",L[i]);
    //}

    return 0;
}
