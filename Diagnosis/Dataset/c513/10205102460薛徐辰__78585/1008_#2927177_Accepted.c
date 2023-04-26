#include<stdio.h>
int f(int x,int y){
    int a=x,b=y,z=0;
    while(a>0||b>0){
        if(a%2!=b%2)z++;
        a=a/2;
        b=b/2;
    }
    return z;
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int x,y,z;
        scanf("%d%d",&x,&y);
        z=f(x,y);
        printf("%d\n",z);
    }
    return 0;
}