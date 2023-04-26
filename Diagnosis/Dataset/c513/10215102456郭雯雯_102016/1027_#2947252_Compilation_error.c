#include<stdio.h>
#include<math.h>

struct point{
    double r,o;
};

int main(){
    int t,a=0;
    scanf("%d",&t);
    while(a<t){
        int n;
        double x,y;
        scanf("%d",&n);
        struct point p[n];
        for(int i=0;i<n;i++){
            scanf("%lf %lf",&x,&y);
            p[i].r=sqrt(x^2+y^2);
        }
    }
    
}