#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 11

int enoughOne(int sr,int sc,int dr,int dc,int l,int(*a)[N])
{
    int cnt=0;
    for(int i=sr;i<=dr;++i){
        for(int j=sc;j<=dc;++j){
            if(a[i][j]==1)cnt++;
        }
    }
    if(cnt>=l)return 1;
    else return 0;
}

int main()
{
    int T,x=0;
    scanf("%d\n",&T);
    while(x<T){
        int r,c,one_num,least;
        scanf("%d%d%d%d\n",&r,&c,&one_num,&least);
        int a[N][N],x,y,sum=0;
        for(int i=0;i<N;++i){
           for(int j=0;j<N;++j)a[i][j]=0;
        }
        for(int i=0;i<one_num;++i){
            scanf("%d %d",&x,&y);
            a[x][y]=1;
        }

        // first scan all elements in matrix
        for(int i=1;i<=r;++i){
            for(int j=1;j<=c;++j){
                // now we got an element: a[i][j]
                // next get its all sub-matrix
                for(int di=i;di<=r;++di){
                    for(int dj=j;dj<=c;++dj){
                        if(enoughOne(i,j,di,dj,least,a))sum++;
                    }
                }
            }
        }
        printf("case #%d:\n",x++);
        printf("%d\n",sum);
    }
    return 0;
}
