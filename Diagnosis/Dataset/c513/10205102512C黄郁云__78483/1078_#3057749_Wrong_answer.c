#include <stdio.h>
#include <stdlib.h>
typedef struct{
    int v ;
    int fz;//分子
    int fm;//分母
}Number;

#define N 1002
Number a[N];

#define Infinity 1000001

int min(int a,int b){
    if(a<= b){
        return a;
    }else{
        return b;
    }
}

int gcd(int a,int b){
    return b == 0?a:gcd(b,a%b);
}

int water_lowest(Number a[N],int s,int base,int l_pos,int r_pos){
//   printf("###1\n");
    int width = r_pos - l_pos -1;
    int high = min(a[l_pos].v,a[r_pos].v) - base;
    int v = width * high;
    if(s>=v){ //水量可以填满那个凹槽，之后还可以继续放出水水
        for(int i = l_pos +1;i <= r_pos-1;i++){
            a[i].v += base+high;
        }
        return s-v;
    }
    else{
        int w_high = base + s/width;
        int r = s%width;
        int fz = r,fm = width;
        int g = gcd(fz,fm);
        fz /=g;
        fm /=g;
        for(int i= l_pos+1;i<=r_pos-1;i++){
            a[i].v = w_high;
            a[i].fz = fz;
            a[i].fm = fm;
        }
        return 0;
    }
}

int cmp(const void* a, const void* b){
   //printf("***%d\n",*(int*)a);
   //printf("***%d\n",*(int*)b);
    return *(int *)a-*(int *)b;
}
void full_final(Number s, Number a[N],int l_pos, int r_pos,int dir){
   // printf("###2\n");
    int arr[N];
    int t = 0;
    for(int i = l_pos; i != r_pos+dir;i+=dir){
        arr[t] = a[i].v;
        t++;
    }
//    printf("###2.1\n");
    qsort(arr,t,sizeof(int),cmp);
//    printf("###2.2\n");
    int cnt;
    for(int j= 1; j <t;j++){
        int c = (arr[j]-arr[j-1])*j;
        if(s.v<c){
            cnt = j;
            break;
        }else{
            s.v-=c;
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

Number full_sub(Number s,Number a[N],int l_pos,int r_pos,int dir){
   //printf("###3\n");
    int t_pos =l_pos;
    while(t_pos != r_pos && a[t_pos +dir].v <= a[t_pos].v) t_pos +=dir;//下坡
    while(t_pos != r_pos && a[t_pos +dir].v >= a[t_pos].v) t_pos +=dir;//下坡

    int high = min(a[t_pos].v,a[l_pos].v);
    int v = 0;
    for(int i = l_pos; i != t_pos+dir;i+=dir ){
        if(a[i].v<high){
            v+=high-a[i].v;
        }
    }
    if(s.v >=v){
        for(int i = l_pos;i !=t_pos+dir;i+=dir){
            if(a[i].v < high) a[i].v = high;
        }
        s.v-= v;
        return s;
    }
    full_final(s, a, l_pos, t_pos, dir);     //水量s全部来填坑，实现思路与下雨题目一样
    Number ret;
    ret.v = 0;
    ret.fz = 0;
    ret.fm = 1;
    return ret;
}

void full(Number s,Number a[N],int l_pos,int r_pos,int dir){
   //printf("###4\n");
    while(s.v > 0 || s.fz >0){
        s = full_sub(s,a,l_pos,r_pos,dir);
    }
}


int water_sub(Number a[N],int n,int s,int pos){
  //printf("###5\n");
    int v = 0;
    int base = a[pos].v;
    int l_pos,r_pos;
    int l_v = 0;
    int r_v = 0;
    //记录左边的山谷
    for(int i = pos-1;i>= 0;i--){
        l_pos = i;
        if(base < a[i].v)
            break;
        l_v +=(-a[i].v+base);
    }

    for(int i = pos+1;i<=n+1;i++){
        r_pos = i;
        if(base < a[i].v)
            break;
        r_v +=(-a[i].v+base);
    }

    v = l_v+r_v;
    //分三种情况讨论
    if( v== 0){
        return water_lowest(a,s,base,l_pos,r_pos);
    }else if(v <=s){
        for(int i = l_pos+1;i <= r_pos-1;i++ ){
            a[i].v  = base;
        }
        return s-v;
    }else if(v > s){
        Number half;
        half.v = s/2;
        half.fz = s % 2;
        half.fm = 2;
        if(half.v >= l_v){
            for(int i = l_pos+1;i<=pos-1;i++){
                a[i].v =base;
            }
            half.v = s-l_v;
            half.fz = 0;
            half.fm = 1;
            full(half,a,pos,r_pos,1);
            return 0;
        }else if(half.v >= r_v){
            for(int i = pos+1;i<=r_pos-1;i++){
                a[i].v =base;
            }
            half.v = s-r_v;
            half.fz = 0;
            half.fm = 1;
            full(half,a,pos,l_pos,-1);
            return 0;

        }else{
            full(half,a,pos,l_pos,1);
            full(half,a,pos,r_pos,-1);
            return 0;


        }
    }
}

void pour_water(Number a[N],int s,int n,int pos){
   //printf("###6\n");
    while(s> 0){
        s = water_sub(a,n,s,pos);
    }
}

int main(){
    int n,s,pos;
    Number a[N];
    scanf("%d %d %d",&n,&s,&pos);
    a[0].v = Infinity;
    a[n+1].v = Infinity; //
    a[0].fm = 1;
    a[0].fz = 0;
    a[n+1].fm = 1;
    a[n+1].fz = 0;
    for(int i =1 ;i <= n;i++){
        scanf("%d",&a[i].v);//得到山丘高度
        a[i].fz = 0;
        a[i].fm = 1;
    }

    //以上是处理完了初始的山谷高度数据

    pour_water(a,s,n,pos);//计算山谷放完水之后高度

    for(int i = 1; i <=n;i++){
        //分门别类输出
        if(a[i].v == 0 && a[i].fz > 0){//那就是只有分数
            printf("%d/%d",a[i].fz,a[i].fm);
        }else{//有整数部分
            printf("%d",a[i].v);
            if(a[i].fz > 0){
                printf("+%d/%d",a[i].fz,a[i].fm);
            }
            printf("%c",(i == n)?'\n':' ');//中间隔空格
        }

    }


    return 0;
}