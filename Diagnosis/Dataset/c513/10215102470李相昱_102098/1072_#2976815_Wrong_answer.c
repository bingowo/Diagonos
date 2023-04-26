#include <stdio.h>
#define ll long long



ll xx,yy;
int ans;
char c[100007];

inline void putx(char a){
    if(xx >= 0)
        a = a == 'E' ? 'W' : 'E';
    c[++ans]=a;
}
inline void puty(char a){
    if(yy >= 0)
        a = a == 'N' ? 'S' : 'N' ;
    c[++ans]=a;
}

void dfs(ll x , ll y){
    if(x == 0 && y == 0)
        return ;
    if(x & 1){//x是奇数
        y >>= 1;
        if(y&1){//y/2是奇数
            if(((x-1) >> 1 & 1) == 0){
                putx('W');
                dfs((x-1) >> 1 , y);
            }

        }
        else {//y/2是偶数
            if((x+1) >> 1 & 1){
                putx('E');
                dfs((x+1) >> 1 , y);
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
        }
        else {//x/2是偶数
            if((y+1) >> 1 & 1){
                puty('N');
                dfs(x , (y+1) >> 1);
            }
        }
    }
}

int main(){
    scanf("%lld%lld",&xx,&yy);
    if((xx&1) == 0 && (yy&1) == 0){
        puts("-1");
        return 0;
    }
    if((xx&1) == 1 && (yy&1) == 1){
        puts("-1");
        return 0;
    }
    dfs(xx,yy);
    printf("%d\n",ans);
    for(int i = 1 ; i <= ans ; ++ i)
        printf("%c",c[ans]);
    return 0;
}
