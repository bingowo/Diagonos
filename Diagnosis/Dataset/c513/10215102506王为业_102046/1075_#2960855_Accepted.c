//digsys\1068.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <math.h>
#include <ctype.h>
#include <limits.h>
/*

*/
//#define LOCAL
#define TRUE 1
#define FALSE 0
typedef long long LL;
typedef unsigned long long ULL;
#define QUESIZE 1000

struct point
{
    int x,y;
};
typedef struct point knot;
knot make_knot(int x,int y)
{
    knot tem={x,y};
    return tem;
}
knot cqueue_i[QUESIZE];
int back=0;//points to empty area
int front=0;//point to the number
void cqueue_push(knot num)
{
    cqueue_i[back]=num;
    if(back==0)
        back=QUESIZE-1;
    else
        --back;
}
knot cqueue_top()
{
    return cqueue_i[front];
}
void cqueue_pop()
{
    if(front==0)
        front=QUESIZE-1;
    else
        --front;
}
int cqueue_empty()
{
    return back==front;
}

int mar[300][300];
char isdone[300][300]={0};

char ans[100];
int anslen=0;
void DFS_recall(knot tem)//simple recall
{
    if(tem.x!=1||tem.y!=1){
        if(mar[tem.x][tem.y-1]>mar[tem.x-1][tem.y]){
            DFS_recall(make_knot(tem.x-1,tem.y));
            ans[anslen++]='D';
        }else{
            DFS_recall(make_knot(tem.x,tem.y-1));
            ans[anslen++]='R';
        }
    }

}


int main()
{
#ifdef LOCAL
freopen("in.txt","r",stdin);
freopen("out.txt","w",stdout);
#endif // LOCAL
    int M,N;
    scanf("%d %d",&M,&N);
    for(int iM=1;iM<=M;++iM){
        for(int iN=1;iN<=N;++iN){
            scanf("%d",&mar[iM][iN]);
        }
    }
    for(int iM=0;iM<=1+M;++iM){
        mar[iM][0]=mar[iM][N+1]=INT_MAX;
    }
    for(int iN=0;iN<=1+N;++iN){
        mar[0][iN]=mar[M+1][iN]=INT_MAX;
    }
    cqueue_push(make_knot(2,1));
    cqueue_push(make_knot(1,2));
    while(!cqueue_empty()){//BFS
        knot tem=cqueue_top();
        cqueue_pop();
        if(mar[tem.x][tem.y-1]>mar[tem.x-1][tem.y]){
            mar[tem.x][tem.y]+=mar[tem.x-1][tem.y];
        }else{
            mar[tem.x][tem.y]+=mar[tem.x][tem.y-1];
        }
        if(tem.x!=M&& !isdone[tem.x+1][tem.y]){
            cqueue_push(make_knot(tem.x+1,tem.y));
            isdone[tem.x+1][tem.y]=1;
        }
        if(tem.y!=N&& !isdone[tem.x][tem.y+1]){
            cqueue_push(make_knot(tem.x,tem.y+1));
            isdone[tem.x][tem.y+1]=1;
        }
    }
    printf("%d\n",mar[M][N]);
    memset(isdone,0,300*sizeof(isdone[0]));
    DFS_recall(make_knot(M,N));
    printf("%s",ans);
    //
}
