#include <stdio.h>
#include <stdlib.h>

int tl(int a,int b,int sum,int s,int alls){
    if(s==alls)return 4*sum;
    if(a<b){
        sum=sum+a;
        s=a*a+s;
        return tl(b-a,a,sum,s,alls);
    }
    else{
        sum=sum+b;
        s=b*b+s;
        return tl(b,a-b,sum,s,alls);
    }
}

int main(){
    int x,y;
    scanf("%d%d",&x,&y);
    printf("%d",tl(x,y,0,0,x*y));
    return 0;
}
