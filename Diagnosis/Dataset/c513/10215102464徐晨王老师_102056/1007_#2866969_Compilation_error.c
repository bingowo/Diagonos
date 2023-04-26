#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char ttt(int y){
    char a[1000];
    int i=0;
    while(y){
        a[i]=y%2;
        y=y/2;
        i++;
    }
    return a;
}
void pd(char c[1000]){
    int z=strlen(c);
    int num;
    int d[100];
    int j=0;
    if(c[0]!=c[1])num=num+1;
    for(int i=1;i<z-1;i++){
        if(c[i]!=c[i-1]&&c[i]!=c[i+1]){
         num=num+1;   
        }
        if(c[i]==c[i-1]||c[i]==c[i+1]){
        d[j]=num;
        num=0;
        j++;
        }
    }
    int e=d[0];
    for(int k;k<j;k++){
        if(d[k]>e)e=d[k];
    }
    printf("%d",e);
}
int main(){
    int x;
    scanf("%d",&x);
    for(int i=0;i<x;i++){
        scanf("%d",&y);
        printf("case #%d:\n",i);
        char b[1000]=ttt(y);
        pd(b);
    }
}