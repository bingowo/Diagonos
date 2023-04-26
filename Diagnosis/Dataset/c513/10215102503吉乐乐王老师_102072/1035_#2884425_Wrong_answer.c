#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
typedef struct{
  int r,h,s;
}yuan;
double max(double a,double b){
    return a>b?a:b;}
int cmp(const void *a,const void*b){
    yuan x=*(yuan*)a;
    yuan y=*(yuan*)b;
    return x.s>y.s?1:-1;
}
int main(){
    int n,m;scanf("%d %d",&n,&m);getchar();
    yuan a[1000];
    for(int i=0;i<n;i++){
        scanf("%d %d",&a[i].r,&a[i].h);getchar();
        a[i].s=2*a[i].r*a[i].h;
    }
    qsort(a,n,sizeof(a[0]),cmp);
    double maxa=0,now=0;
    for(int i=0;i<n;i++){
        now=a[i].s+a[i].r*a[i].r;int idx=1;
        for(int j=i+1;j<n;j++){
            if(idx==m)break;
            if(a[j].r<=a[i].r){now+=a[j].s;idx++;}
        }
        if(idx==m){maxa=max(now,maxa);}
        idx=0;
    }
    printf("%d",(int)maxa);
}
