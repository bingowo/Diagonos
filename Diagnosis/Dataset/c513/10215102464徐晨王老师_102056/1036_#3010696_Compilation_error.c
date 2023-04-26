#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct data{
    long long int x;
    long long int y;
    unsigned long long int d;
};
unsigned long long int myabs(long long int or){
    if(or<0)return -or;
    else return or;
}
unsigned long long int myababs(long long int a,long long int b){
    if(a>0&&b<0)return myabs(a)+myabs(b);
    else if(b>0&&a<0)return myabs(a)+myabs(b);
    else return myabs(x2-x1);    
}
long long int calculate(long long int x1,long long int y1,long long int x2,long long int y2){
    unsigned long long int z;
    z=myababs(x1,x2)+myababs(y1,y2)+1;
    if(z%2==0){
    double zz=log(z)/log(2);
    long long int zzz=0;
    while(zzz<zz)zzz++;
    return (long long int)zzz;
    }
    else if(x1==x2&&y1==y2)return 0;
    else return -1;
}

int cmp(const void*a,const void*b){
    struct data m=*(struct data*)a;
    struct data n=*(struct data*)b;
    if(m.d==n.d){
        if(m.x==n.x){
            return m.y>n.y;
        }
        else return m.x>n.x;
    }
    else return m.d<n.d;
}

int main(){
    int n;
    scanf("%d",&n);
    struct data p[n];
    for(int i=0;i<n;i++){
        scanf("%lld%lld",&p[i].x,&p[i].y);
        p[i].d=myabs(p[i].x)+myabs(p[i].y);
    }
    qsort(p,n,sizeof(p[0]),cmp);
    unsigned long long sum=0;
    for(int i=0;i<n-1;i++){
        long long int step=calculate(p[i].x,p[i].y,p[i+1].x,p[i+1].y);
        if(step==-1)break;
        else sum=sum+step;
    }
    printf("%llu\n%llu",myababs(p[0].x,p[1].x)+myababs(p[0].y,p[1].y),sum);
}
