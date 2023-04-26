#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main(){
    int pro;
    scanf("%d",&pro);
    for(int index=0;index<pro;index++){
        int n,m;scanf("%d%d",&n,&m);
        int search[10000],top=0;
        int out[10000],p=1,loophead=-1,looptail=-1;
        out[0]=n/m;
        n=n%m;
        search[top++]=n;
        for(int i=1;n!=0;i++){
            n*=10;int tmp=n/m;
            out[p++]=tmp;
            n=n%m;
            for(int j=0;j<top;j++){
                if(search[j]==n){loophead=j+1;looptail=i;break;}
            }
            if(loophead>0) break;
            search[top++]=n;

        }
        printf("case #%d:\n",index);
        if(p==1)printf("%d",out[0]);
        else {
            printf("%d.",out[0]);
            for(int i=1;i<p;i++)printf("%d",out[i]);
            printf("\n");
            if(loophead>0) printf("%d-%d\n",loophead,looptail);
        }
    }
    return 0;
}
