#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int ttt(int y,char* a){
    int i=0;
    while(y){
        a[i]=y%2;
        //printf("%d",a[i]);
        y=y/2;
        i++;
    }
    return i;
}
void pd(char *c,int s){

    //printf("%d\n",s);
     int ret=1;
    for(int j=1;j<s;j++){
int num=1;
    for(int i=j;i<s;i++){

       if(c[i]!=c[i-1]&&c[i]!=c[i+1]){
         num=num+1;
        }
        else break;
    }
    if(num>ret)ret=num;

    }
    if(c[0]!=c[1]&&c[1]==c[2])ret=ret+1;
    if(c[s-2]!=c[s-3]&&c[s-2]==c[s-1])ret=ret+1;
    printf("%d\n",ret);

}
int main(){
    int x;
    scanf("%d",&x);
    int y;
    for(int i=0;i<x;i++){
        scanf("%d",&y);
        printf("case #%d:\n",i);
        char b[1000];
        int r=ttt(y,b);
        //printf("%d\n",b[0]);
        pd(b,r);
    }
}
