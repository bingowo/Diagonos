#include<stdio.h>

int main(){
    int T,N;
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        scanf("%d",&N);
        printf("case #%d:\n%d\n",t,N/5+N/25+N/125+N/625);
    }
    return 0;

}
