#include <stdlib.h>
#include <stdio.h>
#include <math.h>
int a[1001];
#define INF 1000000

int gcd(int a,int b){
    return b == 0?a:gcd(b,a%b);
}
int cmp(const void* a,const void *b){
    return(*(int*)a-*(int*)b);
}

void solve(){
    int n = 0;
    int s = 0;
    scanf("%d %d",&n,&s);
    for (int i = 0; i < n;i++){
        scanf("%d",&a[i]);
    }
    qsort(a,n,sizeof(a[0]),cmp);
    a[n] = INF;
    int ans_int = -1 ;
    int ans_fz = -1;
    int ans_fm = -1;
    for(int i = 1; i <=n;i++){
        int c = (a[i]-a[i-1])*i;
        if(s<c){
            ans_int = a[i-1]+s/i;
            ans_fz = s%i;
            ans_fm = i;
            break;
        }else{
            s-=c;
        }
    }
    int g =  gcd(ans_fz,ans_fm);
    ans_fz /= g;
    ans_fm /=g;
    if(ans_int == 0 && ans_fz>0){
        printf("%d/%d",ans_fz,ans_fm);
    }else{
        printf("%d",ans_int);
        if(ans_fz >0){
            printf("+%d/%d",ans_fz,ans_fm);
        }
    }
    printf("\n");

}
int main(){
    solve();
    return 0;
}