#include <stdio.h>
#include <stdlib.h>

#define maxline 32

int f(int x,int y){
    int binary_x[maxline],binary_y[maxline];
    for(int i=0;i<maxline;i++)binary_x[i]=0;
    int i=maxline-1;
    while(x){
        binary_x[i--]=x%2;
        x/=2;
    }
    for(int i=0;i<maxline;i++)binary_y[i]=0;
    i=maxline-1;
    while(y){
        binary_y[i--]=y%2;
        y/=2;
    }
    int res=0;
    for(int j=0;j<maxline;j++)
        if(binary_x[j]!=binary_y[j])
            res++;
    return res;
}

int main(){
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        printf("%d\n",f(x,y));
    }
    return 0;
}


