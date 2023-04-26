#include <stdio.h>
#include <stdlib.h>

void divise(int a,int b){
    printf("%d",a/b);
    if(a%b!=0){
        printf(".");
        int p[300]={0};
        int len=0;
        while(a%b!=0){
            a=10*(a%b);
            p[len]=a/b;
            len++;
            if(len>=299)break;
        }
        int x=1,y=1;
        for(int i=0;i<len;i++){
            int flag;
            for(int j=i+1;j<len;j++){
                if(p[i]==p[j]){
                    flag=1;
                    for(int k=0;k<(j-i);k++){
                        if(p[i+k]!=p[j+k]){
                            flag=0;
                            break;
                        }
                        if(p[i+k]!=p[2*j-i+k]){
                            flag=0;
                            break;
                        }
                    }
                    if(flag==1){
                        x=i+1;
                        y=j;
                    }
                }
                if(flag==1)break;
            }
            if(flag==1)break;
        }
        if(len==299){
        for(int i=0;i<y;i++){
            printf("%d",p[i]);
        }
        if(y!=len){
            printf("\n%d-%d",x,y);
        }
        }
        else{
        for(int i=0;i<len;i++){
            printf("%d",p[i]);
        }            
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
