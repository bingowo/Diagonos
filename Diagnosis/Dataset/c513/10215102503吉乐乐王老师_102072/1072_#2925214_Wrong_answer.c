#include<stdio.h>
int isodd(int a){
    if(a&1==1)return 0;
    return 1;
}
int imp(int dx,int dy){
    if((isodd(dx)&&isodd(dy))||(!isodd(dx)&&!isodd(dy)))return 1;
    return 0;
}
long int labs(long int a){
    if(a<0)a=-a;
    return a;
}
int main(){
    long int x,y;
    scanf("%d %d",&x,&y);
    long int base=1;
    long int dx,dy;
    long int nx,ny;
    nx=ny=0;
    char dic[100];char *p=dic;
    int flag=0;
    int cnt=0;
    while(!((nx==x)&&(ny==y))){
        dx=labs(x-nx)/base;dy=labs(y-ny)/base;
        if(imp(dx,dy)){flag=-1;break;}
        else {
            long int nstep=base;
            base*=2;
            if(dx&1){
                cnt++;
                long int d1=labs(x-(nx-nstep));
                long int d2=labs(x-(nx+nstep));
                dy=labs(y-ny);
                if(d1==0&&dy==0){*p='W';p++;nx-=nstep;continue;}
                if(d2==0&&dy==0){*p='E';p++;nx+=nstep;continue;}
                if(!imp(d1/base,dy/base)){
                    *p='W';p++;nx-=nstep;continue;
                }
                if(!imp(d2/base,dy/base)){
                    *p='E';p++;nx+=nstep;continue;
                }
            }
            if(dy&1){
                cnt++;
                long int d1=labs(y-(ny-nstep));
                long int d2=labs(y-(ny+nstep));
                dx=labs(x-nx);
                if(d1==0&&dx==0){*p='S';p++;ny-=nstep;continue;}
                if(d2==0&&dx==0){*p='N';p++;ny+=nstep;continue;}
                if(!imp(d1/base,dx/base)){
                    *p='S';p++;ny-=nstep;continue;
                }
                if(!imp(d2/base,dx/base)){
                    *p='N';p++;ny+=nstep;continue;
                }
            }
        }
    }
    if(flag==-1)printf("-1");
    else {
        *p='\0';
        printf("%d\n%s",cnt,dic);}
}