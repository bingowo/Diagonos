#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int val;
    int d;
}team;

int find(int a[],int val,int n)
{
    for(int i=0;i<n;i++){
        if(a[i]==val)return i;
    }
    return 1001;
}

int cmp(const void* a,const void* b)
{
    team x=*((team*)a);
    team y=*((team*)b);
    if(x.d!=y.d)return x.d-y.d;
    else{
        return x.val-y.val;
    }
}

int main()
{
    int m,A[500];
    scanf("%d",&m);
    for(int i=0;i<m;i++){
        scanf("%d",&A[i]);
    }
    int n;
    team B[500];
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&B[i].val);
        B[i].d=find(A,B[i].val,m);
    }
    qsort(B,n,sizeof(team),cmp);
    for(int i=0;i<n;i++){
        printf("%d ",B[i].val);
    }
    return 0;
}
