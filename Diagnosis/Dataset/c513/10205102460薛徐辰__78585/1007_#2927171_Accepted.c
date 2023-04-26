#include<stdio.h>
int f(int x){
    int a=x/2,z=1,c,d=1;
    int b=x%2;
    while(a>0){
        c=a%2;
        a=a/2;
        if(c==b){if(d<z)d=z;z=1;}
        else{b=c;z++;}
    }
    if(d<z)d=z;
    return d;
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int a,b;
        scanf("%d",&a);
        b=f(a);
        printf("case #%d:\n%d\n",i,b);
    }
    return 0;
}