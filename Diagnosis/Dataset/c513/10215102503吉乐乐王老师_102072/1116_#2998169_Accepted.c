#include<stdio.h>
#include<stdlib.h>
int isodd(long long int x){
    return x%2==0;
}
int pos(long long int x,long long int y){
    if((isodd(x)&&(!isodd(y)))||((!isodd(x))&&isodd(y)))return 1;
    return 0;
}
int main(){
    long long int x,y;
    scanf("%lld%lld",&x,&y);
    x=llabs(x),y=llabs(y);
    int flag=1;
    int ret=0;
    if(pos(x,y)){
        while(!(x==0&&y==0)){
            if(!isodd(x)){
                if(pos((x-1)/2,y/2)){
                    x-=1;x/=2;y/=2;
                }
                else{
                    x+=1;x/=2;y/=2;
                }
            }
            else{
                if(pos(x/2,(y-1)/2)){
                    y-=1;x/=2;y/=2;
                }
                else{
                    y+=1;x/=2;y/=2;
                }
            }
            ret+=1;
            if((x==0&&y==1)||(x==1&&y==0)){ret+=1;break;}
            if(!pos(x,y)){
                flag=0;break;
            }
        }
    }
    else if(x==0&&y==0)flag=1;
    else {
        flag=0;
    }
    if(flag)printf("%d",ret);
    else printf("-1");
}
