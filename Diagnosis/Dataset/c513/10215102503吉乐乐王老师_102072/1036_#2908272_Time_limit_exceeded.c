#include<stdio.h>
#include<stdlib.h>
unsigned long long int myabs(long long int a){
    if(a<0)a=-a;
    return a;
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
int isodd(long long int a){
    if(a&1==1)return 0;
    else return 1;
}
int main(){
    int n;scanf("%d",&n);getchar();
    mhd *a=(mhd*)malloc(sizeof(mhd)*n);
    for(int i=0;i<n;i++){
        scanf("%lld %lld",&a[i].dx,&a[i].dy);getchar();
        a[i].dis=myabs(a[i].dx)+myabs(a[i].dy);
    }
    qsort(a,n,sizeof(a[0]),cmp);
    int cnt=0;
    for(int i=1;i<n;i++){
        long long int x=a[i].dx-a[i-1].dx;x=x<0?-x:x;
        long long int y=a[i].dy-a[i-1].dy;y=y<0?-y:y;
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
    long long int temp;
    temp=a[0].dx-a[1].dx;temp=temp<0?-temp:temp;
    unsigned long long int retdis=temp;
    temp=a[0].dy-a[1].dy;temp=temp<0?-temp:temp;
    retdis+=temp;
    printf("%llu\n%d",retdis,cnt);
}