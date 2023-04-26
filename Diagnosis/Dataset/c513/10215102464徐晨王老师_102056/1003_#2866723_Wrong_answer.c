#include <stdio.h>
#include <stdlib.h>
struct data{
    long long x;
    int y;
};
int cmp(const void *a,const void *b)
{
    struct data d1,d2;
    d1=*((struct data *)a);
    d2=*((struct data *)b);
    if(d2.y!=d1.y)  
         return d2.y-d1.y;
    else
    {    if(d1.x>d2.x) return 1;
         else return -1;
    }


    

}
int main(){
struct data p[10000];
int t;
scanf("%d",&t);
for(int T=0;T<t;T++){
int n;
scanf("%d",&n);
printf("case #%d:\n",T); 
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
