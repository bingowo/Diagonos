#include <stdio.h>
int num(int n){
    if(n==1)return 1;
    else if(n==2)return 2;
    else if(n==3)return 4;
    else if(n==4)return 8;
    else return (num(n-1)+num(n-2)+num(n-3)+num(n-4));

}
int main(){
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        int n;
        scanf("%d",&n);
        printf("case #%d:\n",i);
        printf("%d",num(n));
    }
}

