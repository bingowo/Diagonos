#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
int cmp(const void *a,const void *b){
    long int *x=(long int*)a;
    long int *y=(long int*)b;
    int i=0;
    while(*x!=-1&&*y!=-1&&*x==*y){x++;y++;}
    return *y-*x;
}
int main(){
    int t;scanf("%d",&t);getchar();
    while(t--){
        int n;scanf("%d",&n);getchar();
        long int a[1000][51];
        for(int i=0;i<n;i++){
            for(int j=0;j<50;j++){
                long int temp;scanf("%ld",&temp);getchar();
                a[i][j]=temp;
                if(temp==-1)break;
            }
        }
        qsort(a,n,sizeof(a[0]),cmp);
        for(int i=0;i<n;i++){
            for(int d=0;a[i][d+1]!=-1;d++)
                printf("%ld ",a[i][d]);
            printf("%ld\n",a[i][d]);
        }
    }
}
