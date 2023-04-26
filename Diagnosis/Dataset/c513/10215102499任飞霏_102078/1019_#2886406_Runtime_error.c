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
    int n,m;
    scanf("%d %d",&n,&m);
    if(m==0)printf("1");
    scanf("%d %d",&n,&m);
    while(n != 0 || m != 0){

        //if(n==0||m==0)continue;
        struct team s[n];
        for(int i = 0;i < n;i++){
            s[i].number = i+1;
            s[i].score = 0;
            s[i].win = 0;
            s[i].lose = 0;
        }
        while(m--){
            int a,b,c;
            scanf("%d %d %d",&a,&b,&c);
            if(c == 1){
                s[a-1].score += 3;
                s[a-1].win++;
                s[b-1].score--;
                s[b-1].lose++;
            }
            else if(c == -1){
                s[b-1].score += 3;
                s[b-1].win++;
                s[a-1].score--;
                s[a-1].lose++;
            }
            else{
                s[a-1].score++;
                s[b-1].score++;
            }

        }
        qsort(s,n,sizeof(struct team),cmp);
        for(int i = 0;i < n;i++){
            printf("%d ",s[i].number);
        }
        printf("\n");
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
