#include<stdio.h>
#include<stdlib.h>
long int myabs(long int a){
    if(a<0)a=-a;
    return a;
}
typedef struct 
{
    long int dx;
    long int dy;
    long int dis;
}mhd;
int cmp(const void*a,const void *b){
    mhd x=*(mhd*)a;
    mhd y=*(mhd*)b;
    if(x.dis==y.dis){
        if(x.dx==y.dx)return x.dy-y.dy;
        return x.dx-y.dx;
    }
    return y.dis-x.dis;
}
int isodd(long int a){
    if(a%2==0)return 1;
    return 0;
}
int main(){
    int n;scanf("%d",&n);getchar();
    mhd *a=(mhd*)malloc(sizeof(mhd)*n);
    for(int i=0;i<n;i++){
        scanf("%ld %ld",&a[i].dx,&a[i].dy);getchar();
        a[i].dis=myabs(a[i].dx)+myabs(a[i].dy);
    }
    qsort(a,n,sizeof(a[0]),cmp);
    int cnt=0;
    for(int i=0;i<n;i++){
        long int x=myabs(a[i].dx),y=myabs(a[i].dy);
        int flag=0;
        while(x||y){
            if((isodd(x)&&isodd(y))||(!isodd(x)&&!isodd(y))){
                flag=1;break;
            }
            if(isodd(x)){
                y+=1;x/=2;y/=2;
                cnt+=1;continue;
            }
            if(isodd(y)){
                x+=1;x/=2;y/=2;
                cnt+=1;continue;
            }
        }
        if(flag)break;
    }
    printf("%ld\n%d",myabs(a[0].dx-a[1].dx)+myabs(a[0].dy-a[1].dy),cnt);
}