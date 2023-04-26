#include <stdio.h>

unsigned long long int f(unsigned long long int x, unsigned long long int y ){
    unsigned long long int ret=0;
    if(x==0 && y==0) ret=0;
    else if(x==1) ret=4*y;
    else if(y==1) ret=4*x;
    else if(x==y) ret=4*x;
    else{
        unsigned long long int da = x>y?x:y;
        unsigned long long int xiao = x<y?x:y;
        ret+=(da/xiao)*4*xiao;
        if(da%xiao!=0) ret+=f(xiao,da%xiao);
    } 
    return ret;
}


int main(){
    unsigned long long int x,y;
    scanf("%llu %llu",&x,&y);
    printf("%llu",f(x,y));
    return 0;
}