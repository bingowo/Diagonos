#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include<math.h>
void Path(long long x,long long y,int k){
    char path[100]={0};int cnt=0;
    while(x!=0||y!=0){
        long long d=(1LL<<(k-1));k--;
        if(llabs(x)>llabs(y)){
            if(x>0){
                x-=d;
                path[cnt++]='E';
            }else{
                x+=d;
                path[cnt++]='W';
            }
        }else{
            if(y>0){
                y-=d;
                path[cnt++]='N';
            }else{
                y+=d;
                path[cnt++]='S';
            }
        }
    }
    for(int i=cnt-1;i>=0;i--){
        printf("%c",path[i]);
    }
}
int main(){
    long long int x,y;
    long long int distance;
    int k;
    scanf("%lld %lld",&x,&y);
    distance=fabs(x)+fabs(y);
    if(distance%2==0&&(distance!=0)){
        printf("-1");
    }else if(distance==0){
        printf("0");
    }else{
        k=1;
        long long int min=1,max=2;
        int res=0;
        for(int i=0;i<42;i++){
            if((min<distance)+1&&(distance+1)<=max){
                res=1;
                break;
            }else{
                k++;
                min*=2;
                max*=2;
            }
        }
        if(res==0) printf("-1");
        else printf("%d\n",k);
    }
    Path(x,y,k);
}
