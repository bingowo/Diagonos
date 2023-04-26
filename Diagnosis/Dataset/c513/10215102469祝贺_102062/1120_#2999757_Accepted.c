#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<limits.h>
#define inf 1005

typedef struct{
    int x,y;
}pos;

int check(pos* vec,pos start,pos end,int k,int n){
    int cnt=0;
    for(int i=0;i<n && cnt<k;i++){
        if((vec[i].x>=start.x && vec[i].x<=end.x) &&
           (vec[i].y>=start.y && vec[i].y<=end.y))
            cnt++;
    }
    if(cnt>=k) return 1;
    else return 0;
}

int main(){
    int t;scanf("%d",&t);
    for(int index=0;index<t;index++){
        int r,c,n,k;scanf("%d%d%d%d",&r,&c,&n,&k);
        int ans=0;
        pos vec[n];
        for(int i=0;i<n;i++){
            scanf("%d%d",&vec[i].y,&vec[i].x);
        }

        for(int i=1;i<=c;i++){
            for(int j=1;j<=r;j++){
                pos start={i,j};
                for(int o=i;o<=c;o++){
                    for(int p=j;p<=r;p++){
                        pos end={o,p};
                        if(check(vec,start,end,k,n)) ans++;
                    }
                }
            }
        }

        printf("case #%d:\n%d\n",index,ans);
    }
    return 0;
}
