#include <stdio.h>
#include <stdlib.h>

int gcd(int m,int n){
    int res,t;
    res=m;
    while(n){
        t=res%n;
        res=n;
        n=t;
    }
    return res;
}


int main(){
    int T;
    scanf("%d",&T);
    getchar();
    for(int i=0;i<T;i++){
        int x=0,y=0;
        char c;
        while((c=getchar())!='\n'){
            y++;
            char d=1;
            for(int i=0;i<8;i++){
                if(c&d)x++;
                d=d<<1;
            }
        }
        y*=8;
        int res=gcd(x,y);
        printf("%d/%d\n",x/res,y/res);
    }
    return 0;
}


