#include<stdio.h>
#include<stdlib.h>

int cmp(const void* a,const void* b){
    int  *a1,*b1;
    a1=(int *)a;
    b1=(int *)b;
    while(*a1!=-1&&*b1!=-1&&*a1==*b1) a1++,b1++;
    return *a1<*b1;
 
}

int main(){
    int line_data[1000][51];
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
    int N;
    scanf("%d",&N);
    for(int k=0; k<N; k++){
        int j=0;              
        while(scanf("%d",&line_data[k][j])&&line_data[k][j]!=-1){
            j++; 
        }
    }
    qsort(line_data,N,sizeof(line_data[0]),cmp); 
    for(int k=0; k<N; k++){
        int j=0; 
        while(line_data[k][j]){
            printf("%d",line_data[k][j]);
            j++;
        }
        printf("\n");
    }
    }
    return 0;
}