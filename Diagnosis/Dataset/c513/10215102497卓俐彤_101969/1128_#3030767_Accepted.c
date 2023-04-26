#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct http{
    char address[301];
};

int cmp(const void*a,const void*b){
    struct http d1,d2;
    d1=*((struct http*)a);
    d2=*((struct http*)b);
    if(strcmp(d1.address,d2.address)<0)return -1;
    else return 1;
}

int main(){
    int T;
    scanf("%d",&T);
    struct http https[T];
    for(int t=0;t<T;t++){
        scanf("%s",https[t].address);
    }
    qsort(https,T,sizeof(https[0]),cmp);
    int flag=0;
    while(https[flag].address[4]!='s'&&flag<T)flag++;
    for(int i=0;i<flag;i++){
        printf("%s\n",https[i].address);
    }
    return 0;
}
