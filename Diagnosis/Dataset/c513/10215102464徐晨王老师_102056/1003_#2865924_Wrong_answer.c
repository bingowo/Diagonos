#include <stdio.h>
#include <stdlib.h>
struct data{
    long long x;
    int y;
};
int cmp(void* a,void* b){
    struct data a1,b1;
    a1=*((struct data *)a);
    b1=*((struct data *)b);
    if(b1.y!=a1.y)return b1.y-a1.y;
    else{
        if(a1.x>b1.x)
        return 1;
        else -1;
    }
    

}
int main(){
struct data p[10000];
int t;
scanf("%d",&t);
for(int T=0;T<t;T++){
printf("case #%d:\n",T);    
int n;
scanf("%d",&n);
int m=0;
while(m<n){
    scanf("%lld",&p[m].x);
    p[m].y=0;
    int z=1;
    for(int i=0;i<64;i++){
        if(p[m].x&z)p[m].y++;
        z=z<<1;
    }
    m++;
}
qsort(p,n,sizeof(p[0]),cmp);
for(int i=0;i<n-1;i++){
    
    printf("%lld ",p[i].x);}
printf("%lld\n",p[n-1].x);
};
return 0;
}
