#include <stdio.h>
#include <stdlib.h>
//回忆公式： s圆圆 = pai r r
//         周长= 2 pai r （侧面积*L)
typedef struct {
    int radius;
    int height;
    long long int product;
}cylinder;
int cmp(const void* a,const void* b){
    cylinder *  B = (cylinder*)b;
    cylinder*  A = (cylinder*)a;
//    printf("%lld\n",A->product);
//    printf("%lld\n",B->product);
//    printf("%d\n",(int)(B->product-A->product));
    return (int)(B-A);
}
long long int cs(long long int ans,long long int cp){
    if(ans>= cp){
        return ans;
    }else{
        return cp;
    }
}

cylinder a[1001];
int main(){
    int n = 0;
    int m = 0;
    scanf("%d %d",&n,&m);
    long long int ans = 0;
    for(int i = 0; i < n;i++){
        scanf("%d %d",&a[i].radius,&a[i].height);
        a[i].product = a[i].height*a[i].radius;
    }
    cylinder ax[1001];
    for (int i = 0;i < n;i++){
        int k = 0;
        for(int j = 0;j < n;j++){
            if(j != i && a[j].radius<=a[i].radius){
                ax[k++] = a[j];
            }
        }
        qsort(ax,k,sizeof(ax[0]),cmp);
        long long area = 0;
        if(k!=0 && k>=m-1){
            for(int cnt = 0;cnt < m-1;cnt++){
                area+=ax[cnt].product;
            }
            ans = cs(ans,area*2+(long long)a[i].radius*a[i].radius+2*a[i].product);
        }
    }
    printf("%lld",ans);

}
