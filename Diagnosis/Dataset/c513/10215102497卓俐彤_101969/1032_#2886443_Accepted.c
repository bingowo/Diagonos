#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int compar(const void*a,const void*b){
    int *s1,*s2;
    s1=(int*)a;
    s2=(int*)b;
    while(*s1!=-1&&*s2!=-1&&*s1==*s2){
        s1++;
        s2++;
    }
    return *s2-*s1;
}
int main(){
    int T,N;
    scanf("%d",&T);
    int line[1001][51];
    for(int t=0;t<T;t++){
        scanf("%d",&N);
        int j=0;
        for(int n=0;n<N;n++){
            j=0;
            while(scanf("%d",&line[n][j])&&line[n][j]!=-1)j++;
        }
        qsort(line,N,sizeof(line[0]),compar);
        for(int n=0;n<N;n++){
            for(j=0;line[n][j+1]!=-1;j++)printf("%d ",line[n][j]);
            printf("%d\n",line[n][j]);
        }
    }
    return 0;
}
