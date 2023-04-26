#include<stdio.h>
#include<stdlib.h>

int cmp_A(const void * a, const void * b){
    return ( *(int*)a - *(int*)b );
}

int cmp_D(const void * a, const void * b){
    return ( *(int*)b - *(int*)a );
}

int main(){
    char ORDER;
    int a[100];
    scanf("%c",&ORDER);
    int i,n=0,j,temp;
    while(scanf("%d",&a[n++])!=EOF) ;
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(a[i]==a[j]){
                for(temp =j;temp<n-1;temp++)
                    a[temp]=a[temp+1];
                j--;
                n--;
            }
        }
    }

    if(ORDER=='A')
        qsort(a,n,sizeof(a[0]),cmp_A);
    else if(ORDER=='D')
        qsort(a,n,sizeof(a[0]),cmp_D);
    for(i=0;i<n-1;i++)
        printf("%d ",a[i]);
    return 0;
}