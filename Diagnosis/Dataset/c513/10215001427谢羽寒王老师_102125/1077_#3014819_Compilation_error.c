#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *x,const void *y)
{
    int p1,p2,d1,d2;
    p1=*((int*)x);
    p2=*((int*)y);




}


int main()
{
    int m,n,i,j,k;
    int A[1000],B[1000];
    scanf("%d",&m);
    for(i=0;i<m,i++){scanf("%d",&A[i]);}
    scanf("%d",&n);
    for(i=0;i<n,i++){scanf("%d",&B[i]);}

    for(j=0;j<n;j++){
        for(k=0;k<m;k++){
            if(B[j]==A[k]){B[j]=k;break;}
            else{B[j]=2000;}
        }

    }
    qsort(B,n,sizeof(int),cmp);

    for(i=0;i<n;i++){
        printf("%d",B[i]);
    }



return 0;
}