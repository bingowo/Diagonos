
#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int v;
    int a;
    int b;
}Number;
int cmp(const void *p1,const void *p2){
    return *(int *)p1-*(int *)p2;
}
int GCD(int m,int n){
    if(n==0){
        return m;
    }
    return GCD(n,m%n);
}
int water_lowest(Number *a,int s,int base,int l_p,int r_p){
    int t=r_p-l_p-1;
    int min=a[l_p].v<a[r_p].v?a[l_p].v:a[r_p].v;
    int need_water=t*(min-base);
    if(s>=need_water){
        for(int i=l_p+1;i<r_p;i++){
            a[i].v=base+min;
        }
        return s-need_water;
    }else{
        int v=s/t,m=1;
        s=s%t;
        m=GCD(s,t);
        for(int i=l_p+1;i<r_p;i++){
            a[i].v=base+v;
            a[i].a=s/m;
            a[i].b=t/m;

        }
        return 0;
    }
}
void full_final(Number s,Number *a,int l_p,int r_p,int d){
    int b[1002];
    int t=0;
    for(int i=l_p;i!=r_p+d;i+=d){
        b[t]=a[i].v;
        t++;
    }
    qsort(b,t,sizeof(int),cmp);
    int cnt=0;
    for(int i=1;i<t;i++){
        int m=(b[i]-b[i-1])*i;
        if(s.v<=m){
            cnt=i;
        }else{
            s.v-=m;
        }
    }
    int a1=s.v*s.b+s.a;
    int b1=s.b*cnt;
    int h=b[cnt-1]+a1/b1;
    a1 %=b1;
    int p= GCD(a1,b1);
    a1/=p;
    b1/=p;
    for(int i=l_p;i!=r_p+d;i+=d){
        if(a[i].v<=h){
            a[i].v=h;
            a[i].a=a1;
            a[i].b=b1;
        }
    }
}
Number full_sub(Number s,Number *a,int l_p,int r_p,int d){
    int t=l_p;
    while (t!=r_p&&a[t+d].v<=a[t].v)
        t+=d;
    while (t!=r_p&&a[t+d].v>=a[t].v)
        t+=d;
    int h=a[l_p].v>a[t].v?a[t].v:a[l_p].v;
    int need=0;
    for(int i=l_p;i!=t+d;i+=d){
        if(a[i].v<h){
            need+=h-a[i].v;
        }
    }
    if(s.v>=need){
        for(int i=l_p;i!=t+d;i+=d){
            if(a[i].v<h){
                a[i].v=h;
            }
        }
        s.v-=need;
        return s;
    }else{
        full_final(s,a,l_p,t,d);
        Number ret;
        ret.v=0;
        ret.a=0;
        ret.b=1;
        return ret;
    }


}
void full(Number s,Number *a,int l_p,int r_p,int d){
    while (s.v>0||s.a>0){
        s= full_sub(s,a,l_p,r_p,d);
    }
}
int water_sub(Number *a,int s,int n,int p){
    int base= a[p].v;
    int l_p,r_p;
    int l_v=0,r_v=0;
    for(int i=p-1;i>=0;i--){
        l_p=i;
        if(a[i].v>base)
            break;
        l_v+=base-a[i].v;
    }
    for(int i=p+1;i<=n+1;i++){
        r_p=i;
        if(a[i].v>base)
            break;
        r_v+=base-a[i].v;
    }
    int v=l_v+r_v;
    if(v==0)
        return water_lowest(a,s,base,l_p,r_p);
    if(v<=s){
        for(int i=l_p+1;i<r_p;i++){
            a[i].v=base;
        }
        return s-v;
    }
    if(v>s){
        Number half;
        half.v=s/2;
        half.a=s%2;
        half.b=2;
        if(half.v>=l_v){
            for(int i=l_p+1;i<p;i++){
                a[i].v=base;
            }
            half.v=s-l_v;
            half.a=0;
            half.b=1;
            full(half,a,p,r_p,1);
            return 0;
        }else if(half.v>=r_v){
            for(int i=p+1;i<r_p;i++){
                a[i].v=base;
            }
            half.v=s-l_v;
            half.a=0;
            half.b=1;
            full(half,a,p,l_p,-1);
            return 0;
        }else{
            full(half,a,p,l_p,-1);
            full(half,a,p,r_p,1);
        }

    }


}
void pour_water(Number *a,int s,int n,int p){
    while(s>0){
        s=water_sub(a,s,n,p);
    }
}
int main() {
    int n,s,p;
    Number a[1002];
    scanf("%d%d%d",&n,&s,&p);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i].v);
        a[i].a=0;
        a[i].b=1;
    }
    a[0].v= 1000000000;
    a[n+1].v=1000000000;
    a[0].a=0,a[n+1].a=0;
    a[0].b=1,a[n+1].b=1;
    pour_water(a,s,n,p);
    for(int i=1;i<=n;i++){
        if(a[i].v==0&&a[i].a>0){
            printf("%d/%d",a[i].a,a[i].b);
        }else{
            printf("%d",a[i].v);
            if(a[i].a>0){
                printf("+%d/%d",a[i].a,a[i].b);
            }
        }
        printf("%c",i==n?'\n':' ');

    }

    return 0;
}
