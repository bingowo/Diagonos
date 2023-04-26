#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define LEN 10000
#define BigNUm 10007
#define Max 1000000

typedef long long lli;

void find(int *div,int cnt,int *ans){
    if(div[cnt-1]==div[cnt-2] && div[cnt-3]==div[cnt-2]){
        ans[0]=1;
        ans[1]=cnt-2;
        ans[2]=cnt-2;
        ans[3]=cnt-2;

    }
    else{
        for(int idx=1;idx<=cnt-2;idx++){
            int start=-1;
            for(int i=0;i<idx;i++){
                if(div[i]==div[idx]){
                    start=i;
                    break;
                }
            }
            if(start!=-1&&idx-start==cnt-idx){
                int start1=start,start2=idx;
                for(;start1<idx && start2<cnt;start1++,start2++){
                    if(div[start1]!=div[start2]) return;
                }
                ans[0]=1;
                ans[1]=start+1;
                ans[2]=idx;
            }
        }
    }
}


int main(){
    int T;scanf("%d",&T);
    for(int I=0;I<T;I++){
        int n,m;scanf("%d%d",&n,&m);
        printf("case #%d:\n0.",I);
        int top=n*10,bottom=m;
        int div[LEN]={0};
        int cnt=0;
        int ans[4]={0};
        int haveCircle=0;
        printf("\n%d %d\n",ans[1],ans[2]);
        while(1){
            if(top<bottom){
                div[cnt++]=0;
            }
            else if(top>=bottom){
                int tmp=top/bottom;
                div[cnt++]=tmp;
                top-=tmp*bottom;
            }
            top*=10;
            find(div,cnt,ans);
            if(top==0) break;
            else if(ans[0]==1){
                haveCircle=1;
                break;
            }
        }
        printf("\n%d %d\n",ans[1],ans[2]);

        if(haveCircle){
            if(ans[3]){
                for(int i=0;i<cnt-2;i++){
                    printf("%d",div[i]);
                }
            }
            else{
                for(int i=0;i<cnt-ans[2]+ans[1]-1;i++){
                    printf("%d",div[i]);
                }
            }
            printf("\n%d-%d",ans[1],ans[2]);
        }
        else{
            for(int i=0;i<cnt;i++){
                printf("%d",div[i]);
            }
        }
        printf("\n");


    }
    return 0;

}
