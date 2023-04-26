#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct 
{
    int posx,posy;
}node;
int func(int x,int px,int dx){
    if(dx==0&&x==px)return -2;//每一次循环都可以到达
    else if(dx>0&&x>=px&&(x-px)%dx==0)return (x-px)/dx;
    else if(dx<0&&x<=px&&(x-px)%dx==0)return (x-px)/dx;
    else return -1;
}
int main(){
    char order[101];
    scanf("%s",order);getchar();
    int len=strlen(order);
    node pos[101];
    for(int i=0;i<101;i++){
        pos[i].posx=pos[i].posy=0;
    }
    for(int i=0;i<len;i++){
        if(order[i]=='U')pos[i+1].posy=pos[i].posy+1;
        if(order[i]=='D')pos[i+1].posy=pos[i].posy-1;
        if(order[i]=='L')pos[i+1].posx=pos[i].posx-1;
        if(order[i]=='R')pos[i+1].posx=pos[i].posx+1;
    }
    int dx=pos[len].posx;
    int dy=pos[len].posy;
    int q;
    scanf("%d",&q);
    while(q--){
        int a,b;
        scanf("%d%d",&a,&b);
        int rx=0,ry=0,rp=0;
        for(int i=0;i<=len;i++){
            rx=func(a,pos[i].posx,dx);
            ry=func(b,pos[i].posy,dy);
            if(rx==-1||ry==-1)rp=0;
            else if(rx==-2||ry==-2)rp=1;
            else if(rx==ry&&rx!=-1)rp=1;
            else rp=0;
            if(rp)break;
        }
        if(rp)printf("Yes\n");
        else printf("No\n");
    }
}