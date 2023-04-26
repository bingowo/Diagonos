#include <stdio.h>
#include <string.h>
typedef struct {
    int x;
    int y;
}loc;
int fun(int dx,int x0,int x){
    if(x>=x0&&dx>0&&((x-x0)%dx==0)){
        return (x-x0)/dx;
    }
    if(x<=x0&&dx<0&&((x0-x)%(-dx)==0)){
        return (x0-x)/(-dx);
    }
    if(dx==0&&x==x0){
        return -2;
    } else
        return -1;
}
int main() {
    char s[101];
    scanf("%s",s);
    int num = strlen(s);
    loc a[num+1];
    a[0].x=0;
    a[0].y=0;
    for(int i=0;i<num;i++){
        if(s[i]=='U'){
            a[i+1].x=a[i].x;
            a[i+1].y=a[i].y+1;
        }else if(s[i]=='D'){
            a[i+1].x=a[i].x;
            a[i+1].y=a[i].y-1;
        }else if(s[i]=='L'){
            a[i+1].x=a[i].x-1;
            a[i+1].y=a[i].y;
        }else if(s[i]=='R'){
            a[i+1].x=a[i].x+1;
            a[i+1].y=a[i].y;
        }
    }
    int dx = a[num].x,dy = a[num].y;
    int q;
    scanf("%d",&q);
    while(q--){
        int x,y,signx,signy,sign=0;
        scanf("%d%d",&x,&y);
        for(int j=0;j<num+1;j++){
            signx= fun(dx,a[j].x,x);
            signy= fun(dy,a[j].y,y);
            if(signx==-2&&(signy>=0)){
                sign=1;
                break;
            }
            if(signy==-2&&(signx>=0)){
                sign=1;
                break;
            }
            if(signy==-2&&(signx==-2)){
                sign=1;
                break;
            }
            if(signy>=0&&signx>=0&&(signy==signx)){
                sign=1;
                break;
            }
        }
        if(sign){
            printf("Yes\n");
        } else{
            printf("No\n");
        }
        
    }
    return 0;
}
