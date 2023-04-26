#include<stdio.h>
typedef struct{
    double s,v,t;
}car;
int main(){
    int n;
    double dn,vn;
    car a[1000];
    scanf("%lf%d",&dn,&n);
    for(int i=0;i<n;i++){
        scanf("%lf%lf",&a[i].s,&a[i].v);
        a[i].s=dn-a[i].s;
        a[i].t=a[i].s/a[i].v;
    }
    for(int i=0;i<n-1;i++){
        if(a[i+1].t<a[i].t)a[i+1]=a[i];
    }
    printf("%.6lf",dn/a[n-1].t);
    return 0;



}