#include <string.h>
#include <stdio.h>
#include <stdlib.h>
int cmp(const void* a, const void* b){
    return *(int*)a-*(int*)b;
}
typedef struct {
    int height,width;
}step;
#define N 1000001
int gcd(int a, int b){
    if(a%b==0) return b;
    return gcd(b,a%b);
}
int H[N];//统计特定高度出现的次数
int main(){
    int n,s;
    scanf("%d%d",&n,&s);
    int cnt = 0;//统计不同高度的种数
    int a[n];//存储哪些高度出现过
    for(int i = 0; i<n; i++){
        int h;
        scanf("%d",&h);
        if(!H[h]) a[cnt++] = h;
        H[h]++;
    }
    qsort(a,cnt,sizeof(int),cmp);
    step valley[cnt];
    for(int i = 0; i<cnt; i++){
        valley[i].height = a[i];
        valley[i].width = H[a[i]];
    }
    int now = 0,wid = valley[now].width;
    while(now+1<cnt&&s>=wid*(valley[now+1].height-valley[now].height)){
        s-=wid*(valley[now+1].height-valley[now].height);
        wid+=valley[++now].width;
    }
    int mheight = valley[now].height;
    mheight+=s/wid;
    s = s%wid;
    if(s==0){
        printf("%d",mheight);
    }
    else{
        int Gcd = gcd(s,wid);
        // printf("%d\n",Gcd);
        s/=Gcd;
        wid/=Gcd;
        printf("%d+%d/%d",mheight,s,wid);
    }
    return 0;
}
//记录当前高度,当前高度所占的宽度,以及下一个的高度
//当剩余雨量大于等于宽度乘以高度差时,把下一个高度赋给当前高度,宽度+下一个高度占据的宽度
//当剩余雨量小于宽度乘以高度差时,输出（当前高度+剩余雨量除以宽度）+（新的剩余雨量/当前宽度）
