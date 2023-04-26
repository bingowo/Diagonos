#include <stdio.h>
#define ll long long
ll xx,yy;
int ans;
char c[100007];
void putx(char a){
    if(xx >= 0)
        a = a == 'E' ? 'W' : 'E';
    c[++ans]=a;
}
void puty(char a){
    if(yy >= 0)
        a = a == 'N' ? 'S' : 'N' ;
    c[++ans]=a;
}

void dfs(ll x , ll y){
    if(x == 0 && y == 0)
        return ;
    if(x == 1){
        putx('W');
        dfs(0,y>>1);
        return ;
    }
    if(y == 1){
        puty('S');
        dfs(x>>1,0);
        return ;
    }
    if(x == 0){
        puty('S');
        dfs(0,y>>1);
        return ;
    }
    if(y == 0){
        putx('W');
        dfs(x>>1,0);
        return ;
    }

    if(x&1){//x是奇数
        y >>= 1;
        if(y&1){//y/2是奇数
            if(((x-1) >> 1 & 1) == 0){
                putx('W');
                dfs((x-1) >> 1 , y);
            }
            else {
                putx('E');
                dfs((x+1) >> 1 , y);
            }

        }
        else {//y/2是偶数
            if((x+1) >> 1 & 1){
                putx('E');
                dfs((x+1) >> 1 , y);
            }
            else {
                putx('W');
                dfs((x-1) >> 1 , y);
            }
        }
    }

    else {//y是奇数
        x >>= 1;
        if(x&1){//x/2是奇数
            if(((y-1) >> 1 & 1) == 0){
                puty('S');
                dfs(x , (y-1) >> 1);
            }
            else {
                puty('N');
                dfs(x , (y+1) >> 1);
            }
        }
        else {//x/2是偶数
            if((y+1) >> 1 & 1){
                puty('N');
                dfs(x , (y+1) >> 1);
            }
            else {
                puty('S');
                dfs(x , (y-1) >> 1);
            }
        }
    }
    return ;
}

int main(){
    scanf("%lld%lld",&xx,&yy);
    if(xx == 0 && yy == 0){
        puts("0");
        return 0;
    }
    if((xx&1) == 0 && (yy&1) == 0){
        puts("-1");
        return 0;
    }
    if((xx&1) == 1 && (yy&1) == 1){
        puts("-1");
        return 0;
    }
    dfs(llabs(xx),llabs(yy));
    printf("%d\n",ans);
    for(int i = 1 ; i <= ans ; ++ i)
        printf("%c",c[i]);
    return 0;
}