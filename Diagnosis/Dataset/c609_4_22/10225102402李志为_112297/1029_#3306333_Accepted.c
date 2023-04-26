#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int A[1001]={0};
int cnt=1;
int cmp(const void*a,const void*b)
{
    int *p1=(int*)a;
    int *p2=(int*)b;
    if(A[*p1]!=0&&A[*p2]!=0) return A[*p1]-A[*p2];
    else if(A[*p1]==0&A[*p2]==0) return *p1-*p2;
    else return A[*p2]-A[*p1];
}
int main()
{
    int m,n;
    scanf("%d",&m);
    for(int i=0;i<m;i++) {
        scanf("%d",&n);
        A[n]=cnt++;
    }
    int B[501];
    scanf("%d",&m);
    for(int i=0;i<m;i++){
        scanf("%d",&B[i]);
    }
    qsort(B,m,sizeof(B[0]),cmp);
    for(int i=0;i<m;i++) printf("%d ",B[i]);


	return 0;
}