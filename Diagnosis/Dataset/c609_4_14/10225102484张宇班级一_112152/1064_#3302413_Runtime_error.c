#include <stdio.h>
long long int f(long long int x,long long int y){
    if(x<y){long long int t=x;x=y;y=t;}
    if(y=0)return 0;
    long long v=x/y*y*4+f(y,x%y);
    return v;
}
int main(){
 long long int x,y;
 scanf("%lld%lld",&x,&y);
 printf("%lld\n",f(x,y));
 return 0;
}

