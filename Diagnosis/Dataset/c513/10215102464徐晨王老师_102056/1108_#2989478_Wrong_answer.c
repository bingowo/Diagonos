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
            if(len>=99)break;
        }
        int x=0,y=0;
        for(int i=0;i<len;i++){
            int flag;
            for(int j=0;(i+j)<len;j++){
                flag=0;
                for(int k=0;k<j;k++){
                    if(p[i+k]!=p[i+j+k])flag=1;
                }
                if(flag==1){
                    x=i;
                    y=i+j-1;
                    break;
                }
            }
            if(flag==1)break;
        }
        for(int i=0;i<len;i++){
            printf("%d",p[i]);
        }
        if(y>0){
            printf("\n%d-%d",x,y);
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
