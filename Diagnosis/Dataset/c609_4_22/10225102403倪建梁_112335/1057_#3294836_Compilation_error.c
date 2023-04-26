#include<stdio.h>
int main(){
    int n;
    n=scanf("%d",&n);
    int i=0;
    getcahr();
    for(;i<n;i++){
        int cnt=0;int m=5;
        int a=scanf("%d",&a);
        while (a){
            cnt += a/5;
            a = a/5;
        }
        printf("case #%d:\n",i);
        printf("%d\n",cnt);
    }
    return 0;
}