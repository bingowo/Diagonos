#include<stdio.h>

char change(int num){
    if(num<10){
        return num+'0';
    }else{
        return num+55;
    }
}

int main(){
    int ans[35];
    int i;
    int T;
    scanf("%d",&T);
    while(T--){
        i=0;
        int N,R;
        scanf("%d%d",&N,&R);
        if(N<0){
            N=-N;
            printf("-");
        }
        while(N!=0){
            ans[i++]=N%R;
            N/=R;
        }

        while(i--){
            printf("%c",change(ans[i]));
        }
        printf("\n");
    }
}
