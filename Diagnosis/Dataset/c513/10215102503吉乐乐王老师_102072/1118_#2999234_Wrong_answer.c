#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int w,h,d;char c;
int arr[201][201];
void right(int times){
    while(times--){
        int tmp[201][201];
        for(int i=1;i<=w;i++){
            for(int j=1;j<=h;j++){
                tmp[i][j]=arr[h-j+1][i];
            }
        }
        for(int i=1;i<=w;i++){
            for(int j=1;j<=h;j++){
                arr[i][j]=tmp[i][j];
            }
        }
        int t=w;w=h;h=t;
    }
}
void left(int times){
    while(times--){
        int tmp[201][201];
        for(int i=1;i<=w;i++){
            for(int j=1;j<=h;j++){
                tmp[i][j]=arr[j][w-i+1];
            }
        }
        for(int i=1;i<=w;i++){
            for(int j=1;j<=h;j++){
                arr[i][j]=tmp[i][j];
            }
        }
        int t=w;w=h;h=t;
    }
}
int main(){
    scanf("%d %d %d %c",&w,&h,&d,&c);
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            scanf("%d",&arr[i][j]);
        }
        getchar();
    }
    if(c=='R'){
        if(d/90%4==1){
            right(1);
        }
        else if(d/90%4==2){
            right(2);
        }
        else if(d/90%4==3){
            right(3);
        }
    }
    else{
        if(d/90%4==1){
            left(1);
        }
        else if(d/90%4==2){
            left(2);
        }
        else if(d/90%4==3){
            left(3);
        }
    }
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            printf("%d ",arr[i][j]);
        }
        putchar('\n');
    }
}
