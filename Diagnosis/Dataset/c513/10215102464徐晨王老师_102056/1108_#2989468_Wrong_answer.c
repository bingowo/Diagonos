#include <stdio.h>
#include <stdlib.h>

void divise(int a,int b){
    printf("%d",a/b);
    if(a%b!=0){
        printf(".");
        int p[100]={0};
        int len=0;
        while(a%b!=0){
            a=10*(a%b);
            p[len]=a/b;
            len++;
            //for()
            if(len>=99)break;
        }
        for(int i=0;i<len;i++){
            printf("%d",p[i]);
        }
    }
}

int main(){
    int T;
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        int n,m;
        scanf("%d%d",&n,&m);
        printf("case #%d:\n",t);
        divise(n,m);
        printf("\n");
    }
    return 0;
}
