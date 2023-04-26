#include<stdio.h>
int main(){
    int T,x,y;
    scanf("%d",&T);
    while(T-->0){
        int p = 0,m=1;
        scanf("%d%d",&x,&y);
        for(int i = 32;i>0;i--,m=m<<1)p+=((x&m)==(y&m))?0:1;
        printf("%d\n",p);
    }
    return 0;
}