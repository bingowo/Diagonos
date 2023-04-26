#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
int cmp(const void *a,const void *b){
    int *x=(int*)a;
    int *y=(int*)b;
    int i=0;
    while(*x!=-1&&*y!=-1){
        if(*x==*y){x++;y++;continue;}
        else return *x>*y?1:-1;
    }
    return 0;
}
int main(){
    int t;scanf("%d",&t);getchar();
    while(t--){
        int n;scanf("%d",&n);getchar();
        int *a[1000];
        for(int i=0;i<n;i++){
            a[i]=(int *)malloc(sizeof(int)*50);
            for(int j=0;j<50;j++){
                int t;scanf("%d",&t);getchar();
                *(a[i]+j)=t;
                if(t==-1)break;
            }
        }
        qsort(a,n,sizeof(int*),cmp);
        for(int i=0;i<n;i++){
            int d=0;
            while(*(a[i]+d)!=-1){
                printf("%d ",*(a[i]+d));
                d++;
            }
            putchar('\n');
        }
    }
}
