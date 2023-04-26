#include <stdio.h>
#include <stdlib.h>
static int hash[1000] = {0};
int cmp(const void*a,const void*b)
{
    int *pa,*pb;
    pa = (int *)a;
    pb = (int *)b;
    if(!hash[*pa]&&!hash[*pb]) return *pa-*pb;
    else if(!hash[*pa]&&hash[*pb]) return 1;
    else if(hash[*pa]&&!hash[*pb]) return -1;
    else return hash[*pa] - hash[*pb];
}
int main()
{
    int m,n,cnt=0;
    scanf("%d",&m);
    int A[m];
    do{
        scanf("%d",&A[cnt++]);
    }while(getchar() == ' ');
    cnt=0;
    scanf("%d",&n);
    int B[n];
    do{
        scanf("%d",&B[cnt++]);
    }while(getchar() == ' ');
    for(int i=0;i<m;i++){
        hash[A[i]] = i+1;
    }
    qsort(B,n,4,cmp);
    for(int i=0;i<n;i++){
        printf("%d%c",B[i],(i == n-1)?'\0':' ');
    }
    return 0;
}