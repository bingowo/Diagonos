#include<stdio.h>
#include<stdlib.h>
int isodd(int a){
    if(a&1)return 0;
    return 1;
}
int imp(int dx,int dy){
    if((isodd(dx)&&isodd(dy))||(!isodd(dx)&&!isodd(dy)))return 1;
    return 0;
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
                long int trywest=nx-nstep;
                long int dx1=labs(x-trywest)/base;
                long int tryeast=nx+nstep;
                long int dx2=labs(x-tryeast)/base;
                dy=labs(y-ny)/base;
                if(!imp(dx1,dy)&&(dx2!=0)){
                    *p='W';p++;nx=trywest;cnt++;continue;
                }
                else {
                    *p='E',p++;nx=tryeast;cnt++;continue;
                }
            }
            if(dy&1){
                long int trysouth=ny-nstep;
                long int dy1=labs(y-trysouth)/base;
                long int trynorth=ny+nstep;
                long int dy2=labs(y-trynorth)/base;
                dx=(x-nx)/base;
                if(!imp(dx,dy1)&&(dy2!=0)){
                    *p='S';p++;ny=trysouth;cnt++;continue;
                }
                else{
                    *p='N';p++;ny=trynorth;cnt++;continue;
                }
            }
        }
    }
    if(flag==-1)printf("-1");
    else {
        *p='\0';
        printf("%d\n%s",cnt,dic);}
}