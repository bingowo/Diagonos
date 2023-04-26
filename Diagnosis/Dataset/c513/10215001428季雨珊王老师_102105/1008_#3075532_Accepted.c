#include<stdio.h>

int main(){
    int T;
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        int x,y;
        scanf("%d%d",&x,&y);
        int a[20]={0},b[20]={0};
        for(int i=0;x;i++){
            a[i]=x%2;
            x/=2;
        }
        for(int i=0;y;i++){
            b[i]=y%2;
            y/=2;
        }
        int count=0;
        for(int i=0;i<20;i++){
            if(a[i]!=b[i])
                count++;
        }
        printf("%d\n",count);
    }
    return 0;
}
