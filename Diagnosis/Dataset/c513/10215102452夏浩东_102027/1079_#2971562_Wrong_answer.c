#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a,const void *b)
{
    return *(int*)a-*(int*)b;
}
int* func(int* L,int n)
{
    int *A = (int*)malloc((n+1)*n/2*sizeof(int));
    int begin=0,end=0,sum=0,k=0;
    while(begin<n)
    {
    	
        sum+=L[end++];
        A[k++]=sum;
        if(end==n){begin++;end=begin;sum=0;}
    }
    qsort(A,(n+1)*n/2,sizeof(int),cmp);
    return A;
}
int main()
{
    int cnt=0;
    scanf("%d",&cnt);
    for(int nn=0;nn<cnt;nn++)
    {
        int n=0,m=0;
        scanf("%d %d",&n,&m);
        int L[1000];
        for(int i=0;i<1000;i++) L[i]=0;
        for(int i=0;i<n;i++) scanf("%d",&L[i]);
        int *NL =(int*)malloc((n+1)*n/2*sizeof(int));
        NL=func(L,n); 
        
        printf("case #%d:\n",nn);
        for(int i=0;i<m;i++){
            int a=0,b=0;
            int sum=0;
            scanf("%d %d",&a,&b);
            for(int j=a-1;j<b;j++) sum+=NL[j];
            printf("%d\n",sum);
        }
        free(NL);
    }
}