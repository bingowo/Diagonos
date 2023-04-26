#include<stdio.h>
int main(){
    int T,i=0,j=0,p=0;
    scanf("%d",&T);
    for(i=0;i<T;i++){
        int n;
        scanf("%d",&n);
        int j=0,count=0;
        while(n){
            int r[50];
            r[j]=(n%2333);
            n/=2333;
            j++;
            count++;
        }
        for(j=count-1;j>=0;j--){
            printf("%d\t",r[j]);
        }
        printf("\n");
        }   
    return 0;
}