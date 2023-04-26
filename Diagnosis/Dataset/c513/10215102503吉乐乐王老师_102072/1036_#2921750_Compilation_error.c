#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define N 40
void myultoa(int r1[],unsigned long long int d1){
    for(int i=N-1;i>0;i--){
        r1[i]=d1%10;
        d1/=10;
    }
}
void add(int ret[],int r1[],int r2[]){
    for(int i=N-1;i>0;i--){
        ret[i]=r1[i]+r2[i];
        ret[i-1]=ret[i]/10;
        ret[i]%=10;
    }
}
typedef struct 
{
    long long int dx;
    long long int dy;
    unsigned long long int dis;
}mhd;
int cmp(const void*a,const void *b){
    mhd x=*(mhd*)a;
    mhd y=*(mhd*)b;
    if(x.dis==y.dis){
        if(x.dx==y.dx)return x.dy>y.dy?1:-1;
        return x.dx>y.dx?1:-1;
    }
    return x.dis<y.dis?1:-1;
}
int isodd(unsigned long long int a){
    if(a&1==1)return 0;
    else return 1;
}
long long int labs(long long int a){
    if(a<0)a=-a;
    return a;
}
int main(){
    int n;scanf("%d",&n);getchar();
    mhd *a=(mhd*)malloc(sizeof(mhd)*n);
    for(int i=0;i<n;i++){
        scanf("%lld %lld",&a[i].dx,&a[i].dy);getchar();
        a[i].dis=labs(a[i].dx)+labs(a[i].dy);
    }
    qsort(a,n,sizeof(a[0]),cmp);
    int cnt=0;
    for(int i=1;i<n;i++){
        unsigned long long int x=labs(a[i].dx-a[i-1].dx);
        unsigned long long int y=labs(a[i].dy-a[i-1].dy);
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
    unsigned long long int d1=labs(a[1].dx-a[0].dx);
    unsigned long long int d2=labs(a[1].dy-a[0].dy);
    int r1[N]={0},r2[N]={0},ret[N]={0};
    myultoa(r1,d2);myultoa(r2,d2);
    add(ret,r1,r2);
    int i=0;
    while(ret[i]==0)i++;
    while(i<N)printf("%d",ret[i]);
    printf("\n%d",cnt);
}