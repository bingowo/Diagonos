#include<stdio.h>
int main(){
    int T;
    scanf("%d",&T);
    for(int j=0;j<T;j++){
        int N,R;
        scanf("%d%d",&N,&R);
        int b=1,a[100];
        for(int i=0;b;i++){
            a[i]=N%R;
            N/=R;
            if(N/R==0) b=0;
        }
        for(int i=99;i>=0;i--){
            if(a[i]==EOF) continue;
            if(a[i]<10) printf("%d",a[i]);
            else printf("%c",a[i]-10+'A');
        }
        printf("\n");
    }
}