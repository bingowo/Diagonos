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
        }
        printf("case #%d:\n",t);
        for(int i=0;i<8;i++){
            if(p[i]!=0&&flag==1){
                if(p[i]==-1)printf("-");
                else if(p[i]==1)printf("+");
                else if(p[i]<-1)printf("%d",p[i]);
                else if(p[i]>1)printf("+%d",p[i]);
                if(i!=7)printf("x^%d",8-i);
                else printf("x");
            }
            if(p[i]!=0&&flag==0){
                if(p[i]==-1)printf("-");
                else if(p[i]<-1)printf("%d",p[i]);
                else if(p[i]>1)printf("%d",p[i]);
                if(i!=7)printf("x^%d",8-i);
                else printf("x");
                flag=1;
            }
        }
        if(p[8]!=0){
            if(flag==1){
                if(p[8]>0)printf("+%d",p[8]);
                else if(p[8]<0)printf("%d",p[8]);
            }
            else{
                printf("%d",p[8]);
                flag=1;
            }
        }
        if(flag==0)printf("0");
        printf("\n");
        
    }
    return 0;
}