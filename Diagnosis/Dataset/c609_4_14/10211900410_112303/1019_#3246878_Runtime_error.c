#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int length(int x)
{
    int l=0;
    if(x<0) x=-x;
    do{
        l++;
        x/=10;
    }while(x!=0);
    return l;
}
int cmp(const void *a,const void *b)
{
    return *(int*)a-*(int*)b;
}
int cmp_l(const void *a,const void *b)
{
    return ((int *)b)[1]-((int *)a)[1];
}
int main()
{
    int N[1000000][2];
    int i=0;
    while(scanf("%d",&N[i][0])!='\n'){
        N[i][1]=length(N[i][0]);
        i++;
    }
    qsort(N,i,sizeof(int),cmp_l);
    for(int j=0;j<i;j++){
        int M[10000];
        for(int k=j;k<i;k++){
            if(length(N[k][0])==length(N[j][0])){
                M[k-j]=N[k][0];
            }
            else{
                qsort(M,k-j,sizeof(int),cmp);
                for(int l=0;l<k-j;l++){
                    printf("%d",M[l]);
                }
            }
        }
    }
    return 0;
}
