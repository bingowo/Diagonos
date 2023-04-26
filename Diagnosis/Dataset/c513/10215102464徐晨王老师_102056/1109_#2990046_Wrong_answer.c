#include <stdio.h>
#include <stdlib.h>
int main(){
    int T;
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        int p[9];
        int flag=0;
        for(int i=0;i<9;i++){
            scanf("%d",&p[i]);
            if(p[i]!=0)flag=1;
        }
        printf("case #%d:\n",t);
        if(flag){
        if(p[0]!=0){
            if(p[0]==-1)printf("-");
            else if(p[0]<-1)printf("%d",p[0]);
            else if(p[0]>1)printf("%d",p[0]);
            printf("x^8");
        }
        for(int i=1;i<8;i++){
            if(p[i]!=0){
            if(p[i]==-1)printf("-");
            else if(p[i]==1)printf("+");
            else if(p[i]<-1)printf("%d",p[i]);
            else if(p[i]>1)printf("+%d",p[i]);
            printf("x^%d",8-i);                
            }
        }
        if(p[8]!=0){
            if(p[8]>0)printf("+%d",p[8]);
            else if(p[8]<0)printf("%d",p[8]);
        }
        printf("\n");
        }
        else{
            printf("0\n");
        }
    }
    return 0;
}