#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>


int main()
{
    int m;scanf("%d",&m);int A[m];
    for(int i=0;i<m;i++)scanf("%d",&A[i]);
    int n;scanf("%d",&n);int B[n];
    for(int i=0;i<n;i++)scanf("%d",&B[i]);
    int cmp(const void *a,const void *b)
    {
        int a1=*(int *)a;int b1=*(int *)b;
        int pa=m,pb=m;
        for(int i=0;i<m;i++){
            if(a1==A[i])pa=i;
            if(b1==A[i])pb=i;
        }
        if(pa!=pb)return pa>pb?1:-1;
        else return a1>b1?1:-1;
    }
    qsort(B,n,sizeof(int),cmp);
    for(int i=0;i<n;i++)printf("%d ",B[i]);
    return 0;
}
