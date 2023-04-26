#include <stdio.h>
#include <stdlib.h>

long long a[10010];

int f(int x){
    int f=0;
    if (x<0){
        x=-x;
        f=1;
    }
    int p[10010];
    for (int i=1;i<=100;i++) p[i]=0;
    int i=1;
    while (x!=0){
        p[i]=x%2;
        x=x/2;
        i++;
    }
    if (f==1){
        for (int i=1;i<=64;i++)
            if (p[i]==1) p[i]=0;
            else p[i]=1;
        int i=1;
        while (p[i]==1){
            p[i]=0;
            i++;
        }
        p[i]=1;
    }
    int ans=0;
    for (int i=1;i<=64;i++)
        ans+=p[i];
    return ans;
}

int cmp(const void* x,const void* y){
    int xx=*(long long*)x,yy=*(long long*)y;
    if (f(xx)==f(yy)){
        return xx-yy;
    }
    else return f(yy)-f(xx);
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int l=1;l<=t;l++){
        int n;
        scanf("%d",&n);
        for (int i=1;i<=n;i++){
            scanf("%lld",&a[i]);
        }
        qsort(a+1,n,sizeof(a[1]),cmp);
        printf("case #%d:\n",l-1);
        for (int i=1;i<=n;i++)
            printf("%lld ",a[i]);
        printf("\n");
    }
    return 0;
}
