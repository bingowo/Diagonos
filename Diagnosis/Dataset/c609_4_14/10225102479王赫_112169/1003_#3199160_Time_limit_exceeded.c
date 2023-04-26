#include<stdio.h>
int main(){
    int T,i=0,j=0,n[300],m[300],p;
    scanf("%d",&T);
    for(i=0;i<T;i++){
        scanf("%d\n",&n[i]);
    };
    for(i=0;i<T;i++){
        while(n[i]){
           m[j]+=(n[i]%2333);
           j++;
           p++;
        };
    for(j=0;j<p;j++){
        printf("%d\t",m[j]);
    };
    }
    return 0;
}