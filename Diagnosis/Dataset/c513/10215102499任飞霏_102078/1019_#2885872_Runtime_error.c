#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct team{
    int number;
    int score;
    int win;
    int lose;
};

int cmp(const void* a,const void* b);

int main()
{
    int n,m,i;
    scanf("%d %d",&n,&m);
    while(n != 0 && m != 0){
        while(m--){
            struct team s[n];
            for(i = 1;i <= n;i++){
                s[i].number = i;
                s[i].score = 0;
                s[i].win = 0;
                s[i].lose = 0;
            }
            int a,b,c;
            scanf("%d %d %d",&a,&b,&c);
            if(c == 1){
                s[a].score += 3;
                s[a].win++;
                s[b].score--;
                s[b].lose++;
            }
            else if(c == -1){
                s[b].score += 3;
                s[b].win++;
                s[a].score--;
                s[a].lose++;
            }
            else{
                s[a].score++;
                s[b].score++;
            }
            qsort(s,n,sizeof(struct team),cmp);
            for(i = 1;i <= n;i++){
                printf("%d ",s[i].number);
            }
            printf("\n");

        }
    scanf("%d %d",&n,&m);
    }
    return 0;
}

int cmp(const void* a,const void* b)
{
    struct team x,y;
    x = *((struct team*)a);
    y = *((struct team*)b);
    if(x.score != y.score){
        return y.score - x.score;
    }
    else if(x.win != y.win){
        return y.win - x.win;
    }
    else if(x.lose != y.lose)
        return x.lose - y.lose;
    else
        return x.number - y.number;
}
