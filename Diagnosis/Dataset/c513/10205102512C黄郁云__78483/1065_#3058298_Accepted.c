#include <stdio.h>
int up[21];
int down[21];
int sum[21];

int binary(int n,int m,int t,int left,int x){
        up[2] = down[2] = (t+left)/2;
        for(int i = 3; i < n;++i){
            up[i] = up[i-1]+up[i-2];
            down[i] = up[i-1];
            sum[i] = sum[i-1] + up[i]- down[i];
        }
        if(sum[n-1]<m){
            binary(n,m,t,(t+left)/2,x);
            return 0;
        }else if(sum[n-1]>m){
            binary(n,m,(t+left)/2,left,x);
            return 0;
        }if(sum[n-1] == m){
            printf("%d\n",sum[x]);
        }

}
int main(){
    int a,n,m,x;
    scanf("%d %d %d %d",&a,&n,&m,&x);
    //初始化一些函数
    up[1] = a;
    down[1] = 0;
    sum[1] = a;
    sum[2] = a;
    //二分法
    binary(n,m,m,0,x);


//    for(int t = 0; t <=m ;++t){
//        up[2] = down[2] = t;
//        for(int i = 3; i < n;++i){
//            up[i] = up[i-1]+up[i-2];
//            down[i] = up[i-1];
//            sum[i] = sum[i-1] + up[i]- down[i];
//        }
//        if(sum[n-1] == m){
//            printf("%d",sum[x]);
//            break;
//        }
//    }
}

