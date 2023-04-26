#include<stdio.h>
#include<string.h>
typedef struct{
    int x,y;
}point;
int solve(int a,int x,int dx){
    int r=a-x,t=dx;
    if(t==0&&r!=0)return -2;
    if(t==0&&r==0)return -1;
    if(r%t!=0||r/t<0)return -2;
    return r/t;
}
int main(){
    char s[101];
    scanf("%s",s);
    point move[101];
    move[0].x=move[0].y=0;
    for(int i=0;i<strlen(s);i++){
        move[i+1].x=move[i].x;
        move[i+1].y=move[i].y;
        switch (s[i])
        {
        case 'U':
            move[i+1].y+=1;
            break;
        case 'D':
            move[i+1].y-=1;
            break;
        case 'L':
            move[i+1].x-=1;
            break;
        case 'R':
            move[i+1].x+=1;
            break;
        default:
            break;
        }
    }
    int dx=move[strlen(s)].x,dy=move[strlen(s)].y;
    int q;
    scanf("%d",&q);
    while(q--){
        int a,b;
        scanf("%d%d",&a,&b);
        int flag=0;
        for(int i=0;i<=strlen(s);i++){
            int solve1=solve(a,move[i].x,dx);
            int solve2=solve(b,move[i].y,dy);
            if(solve1==-2||solve2==-2)continue;
            if(solve1==-1||solve2==-1||solve1==solve2){
                    flag=1;break;
            }
            if(flag)break;
        }
        if(flag)printf("Yes\n");
        else printf("No\n");
    }
}