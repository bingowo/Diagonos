#include<stdio.h>
#include<stdlib.h>
#define N 40
void add(int r[],int a[],int b[]){
    for(int i=N-1;i>0;i--){
        r[i]=a[i]+b[i];
        r[i-1]+=r[i]/10;
        r[i]=r[i]%10;
    }
}
void minus(int r[],int a[],int b[]){
    for(int i=N-1;i>0;i--){
        if(a[i]<b[i]){
            a[i]+=10;a[i-1]--;
        }
        r[i]=a[i]-b[i];
    }
}
typedef struct 
{
    long long int dx;
    long long int dy;
    int dis[N];
}mhd;
int cmp(const void*a,const void *b){
    mhd x=*(mhd*)a;
    mhd y=*(mhd*)b;
    for(int i=0;i<N;i++){
        if(x.dis[i]!=y.dis[i])return x.dis[i]<y.dis[i]?1:-1;
    }
    if(x.dx!=y.dx)return x.dx>y.dx?1:-1;
    return x.dy>y.dy?1:-1;
}
int isodd(unsigned long long int a){
    if(a&1==1)return 0;
    else return 1;
}
void itoi(int aa[],long long int a){
    if(a<0)a=-a;
    int i=N-1;
    do{
        aa[i]=a%10;
        a/=10;
        i--;
    }while(a);
}
int main(){
    int n;scanf("%d",&n);getchar();
    mhd *a=(mhd*)malloc(sizeof(mhd)*n);
    for(int i=0;i<n;i++){
        scanf("%lld %lld",&a[i].dx,&a[i].dy);getchar();
        int aa[N]={0};int bb[N]={0};
        for(int i=0;i<N;i++)a[i].dis[i]=0;
        itoi(aa,a[i].dx);itoi(bb,a[i].dy);
        add(a[i].dis,aa,bb);
    }
    qsort(a,n,sizeof(a[0]),cmp);
    int cnt=0;
    for(int i=1;i<n;i++){
        unsigned long long int x=(a[i].dx-a[i-1].dx)>0?(a[i].dx-a[i-1].dx):(a[i-1].dx-a[i].dx);
        unsigned long long int y=(a[i].dy-a[i-1].dy)>0?(a[i].dy-a[i-1].dy):(a[i-1].dy-a[i].dy);
        int flag=0;
        while(x||y){
            if((isodd(x)&&isodd(y))||(!isodd(x)&&!isodd(y))){
                flag=1;break;
            }
            if(isodd(x)){
                x/=2;y/=2;cnt+=1;
                if(x==0&&y==0)break;
                if(!isodd(x)&&!isodd(y)||(isodd(x)&&isodd(y)))y+=1;
                continue;
            }
            if(isodd(y)){
                x/=2;y/=2;cnt+=1;
                if(x==0&&y==0)break;
                if(!isodd(x)&&!isodd(y))x+=1;
                continue;
            }
        }
        if(flag)break;
    }
    unsigned long long int x=(a[1].dx-a[0].dx)>0?(a[1].dx-a[0].dx):(a[0].dx-a[1].dx);
    unsigned long long int y=(a[1].dy-a[0].dy)>0?(a[1].dy-a[0].dy):(a[0].dy-a[1].dy);
    int aa[N]={0},bb[N]={0};
    itoi(aa,x);itoi(bb,y);
    int ret[N]={0};
    add(ret,aa,bb);
    int i=0;
    while(i<N&&ret[i]==0)i++;
    while(i<N){
        printf("%d",ret[i]);
        i++;}
    printf("\n%d",cnt);
}