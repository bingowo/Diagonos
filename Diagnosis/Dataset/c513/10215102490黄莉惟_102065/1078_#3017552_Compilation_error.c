#include <stdio.h>
#include<string.h>
#include<math.h>
#define N 1002
#define INF 1000009
typedef struct{
    int v;
    int fz;//分子
    int fm;//分母
}Number;

int main(){
    Number a[N];
    int n,s,p;  //n表示这个世界的总宽度， s表示总放水量， p表示放水的位置。
    scanf("%d %d %d",&n,&s,&pos);
    a[0].v=INF;a[n+1].v=INF;//边界高度无穷高
    a[0].fz=a[n+1].fz=0;
    a[0].fm=a[n+1].fm=1;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i].v)//输入地形高度
        a[i].fz=0;
        a[i].fm=1;
    }
    pour_water(a,s,n.pos);
    for(int i=1;i<=n;i++){
        if(a[i].v==0&&a[i].fz>0){
            printf("%d %d",a[i].fz,a[i].fm);
        }else{
            printf("%d",a[i].v);
            if(a[i].fz>0){
                printf("+%d/%d",a[i].fz,a[i].fm);
            }
        }
        printf("%c",(i==n)?'\n':' ');
    }
    return 0;
}

void pour_water(Number *a,int s,int n,int p){
    //分三种情况进行填坑，返回剩余的放水量, 进行新一轮放水
    //当水量为0结束
    while(s>0){
        s=water_sub(a,s,n,p);
    }
}

int water_sub(Number *a,int s,int n,int pos){
    int base=a[pos].v;//base=倒入位置的地形高度
    int l_pos,r_pos;
    int l_v=0,r_v=0;
    for(int i=pos-1;i>=0;i--){//计算L_v，记录左端位置l_pos
        l_pos=i;
        if(a[i].v>base) break;
        l_v+=base-a[i].v;
    }
    for(int i=pos+1;i<=n+1;i++){//计算R_v，记录右端位置r_pos
        r_pos=i;
        if(a[i].v>base) break;
        r_v+=base-a[i].v;
    }
    int v=l_v+r_v;
    //V=0，放水位置地面高度最低，即其左右地面均不低于放水位置,分为两种：
    //(1)水量s 能放满当前凹槽，就先放满，剩余水量再进行新一轮放水
    //(2)水量s 不能放满当前凹槽，则计算能放到的高度
    if(v==0){return water_lowest(a,s,base,I_pos,r_pos);}
    //第二种情况： V≤s
    //放水量足够将左边右边的坑填满到与当前放水位置平齐，就先填满，然后剩余水量，又重新放水
    if(v<=s){
        for(int i=l_pos+1;i<=r_pos-1;i++){
            a[i].v=base;
        }
        return s-v;
    }
    //放水量s不能填满左右坑，先考虑一半水量是否能填满一边的坑，然后再考虑填另一边坑
    //注意：数量可能带分数
    if(v>s){
        Number half;
        half.v=s/2;
        half.fz=s%2;
        half.fm=2;
        if(half.v>=l_v){//一半水量填满左边坑,剩余水量填右边部分坑
            for(int i=l_pos+1;i<=pos-1;i++){
                a[i].v=base;
            }
            half.v=s-l_v;
            half.fz=0;
            half.fm=1;
            full(half,a,pos,r_pos,1);//剩余水量填右边部分坑
            return 0;
        }else if(half.v>=r_v){
            for(int i=pos+1;i<=r_pos-1;i++){
                a[i].v=base;
            }
            half.v=s-r_v;
            half.fz=0;
            half.fm=1;
            full(half,a,pos,l_pos,-1);
            return 0;
        }
        full(half,a,pos,l_pos,-1);//一半水量填左边部分坑
        full(half,a,pos,r_pos,-1);//一半水量填右边部分坑
        return 0;
    }
    
}

int water_lowest(Number *a,int s,int base,int lpos,int rpos){
    int width=rpos-lpos-1;
    int high=min(a[pos].v,a[rpos].v)-base;
    int v=width*high;
    if(s>=v){//水量s 能放满当前凹槽，就先放满，剩余水量再进行新一轮放水
        for(int i=lpos+1;i<=rpos-1;i++){
            a[i].v=base+high;
        }
        return s-v;
    }else{//水量s 不能放满当前凹槽，则计算能放到的高度
        int w_high=base+s/width;
        int r=s%width;
        int fz=r,fm=width;
        int g=gcd(fz,fm);
        fz/=g;fm/=g;
        for(int i=lpos+1;i<=rpos-1;i++){
            a[i].v=w_high;
            a[i].fz=fz;
            a[i].fz=fm;
        }
        return 0;
    }
}


void full(Number s,Number *a,int l_pos,int r_pos,int dir){
    //从l_pos位置搜索到r_pos位置，用水量s填充一个个坑
    // dir=-1表示填充左边的部分坑，dir=1,表示填充右边部分坑
    //从离放水位置最近的坑开始一个坑一个坑填水
    while(s.v>0||s.fz>0){
        s=full_sub(s,a,l_pos,r_pos,dir);//每次填一个坑，返回剩余的水量
    }
}

Number full_sub(Number s,Number *a,int l_pos,int r_pos,int dir){
    int t_pos=l_pos;
    while (t_pos != r_pos && a[t_pos + dir].v <= a[t_pos].v) t_pos += dir;
    while (t_pos != r_pos && a[t_pos + dir].v >= a[t_pos].v) t_pos += dir;  //找坑

    int high = min(a[l_pos].v, a[t_pos].v);    
    int v = 0;
    for (int i = l_pos; i != t_pos + dir; i += dir) {  // 填坑需要的水量
        if (a[i].v < high) v += high - a[i].v;
    }
    if (s.v >= v) {  //能填满坑
        for (int i = l_pos; i != t_pos + dir; i += dir) {
            if (a[i].v < high) a[i].v = high;
        }
        s.v -= v;
        return s;
    }
    full_final(s, a, l_pos, t_pos, dir);     //水量s全部来填坑，实现思路与下雨题目一样
    Number ret;
    ret.v = 0;
    ret.fz = 0;
    ret.fm = 1;
    return ret;

}
void full_final(Number s, Number *a, int l_pos, int r_pos, int dir)
 {
    //剩下的水s都放到这个山谷，不会填满
    int arr[N];
    int t = 0;
    for (int i = l_pos; i != r_pos + dir; i += dir) {
        arr[t] = a[i].v;
        t++;
    }
    qsort(arr, t, sizeof(int), cmpfunc);
    int cnt;
    for (int i = 1; i < t; i++) {
        int c = (arr[i] - arr[i - 1]) * i;
        if (s.v < c) {
            cnt = i;
            break;
        }
        else {
            s.v -= c;
        }
    }
    int fz = s.v * s.fm + s.fz;
    int fm = s.fm * cnt;
    int high_zs = arr[cnt - 1] + fz / fm;
    fz %= fm;
    int g = gcd(fz, fm);
    fz /= g;
    fm /= g;
    for (int i = l_pos; i != r_pos + dir; i += dir)     
    {
        if (a[i].v <= high_zs) {
            a[i].v = high_zs;
            a[i].fz = fz;
            a[i].fm = fm;
        }
    }
}


