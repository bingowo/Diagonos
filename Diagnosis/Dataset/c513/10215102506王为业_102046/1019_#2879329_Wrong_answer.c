#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#define TRUE 1
#define FALSE 0

struct team{
    int score,win,fail,num;
};
struct team arr[12];
int cmp(struct team*x,struct team*y)
{
    if(x->score==y->score){
        if(x->win==y->win){
            if(x->fail==y->fail){
                return x->num<y->num?-1:1;
            }else{
                return x->fail<y->fail?-1:1;
            }
        }else{
            return x->win>y->win?-1:1;
        }
    }else{
        return x->score>y->score?-1:1;//if x is larger,x is before
    }
}

int main()
{
int n,m;
while(scanf("%d %d",&n,&m)&&n!=0&&m!=0){
    int a,b,c;
    memset(arr,0,12*sizeof(struct team));
    for(int i=1;i<=10;++i){
        arr[i].num=i;
    }
    while(m--){//there is no ZERO team
        scanf("%d %d %d",&a,&b,&c);
        switch(c){
    case 1:
        arr[a].score+=3;
        ++arr[a].win;
        --arr[b].score;
        ++arr[b].fail;
        break;
    case -1:
        arr[b].score+=3;
        ++arr[b].win;
        --arr[a].score;
        ++arr[a].fail;
        break;
    case 0:
        ++arr[a].score;
        ++arr[b].score;
        break;
        }
    }
    qsort(arr+1,n,sizeof(struct team),cmp);
    for(int i=1;i<n;++i){
        printf("%d ",arr[i].num);
    }printf("%d\n",arr[n].num);
}
}
